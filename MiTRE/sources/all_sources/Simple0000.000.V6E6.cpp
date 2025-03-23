#include <windows.h>
#include <winternl.h>
#include <stdio.h>

typedef NTSTATUS(WINAPI* NtCreateThreadExType)(
    PHANDLE ThreadHandle,
    ACCESS_MASK DesiredAccess,
    PVOID ObjectAttributes,
    HANDLE ProcessHandle,
    PVOID StartRoutine,
    PVOID Argument,
    ULONG CreateFlags,
    ULONG ZeroBits,
    ULONG StackSize,
    ULONG MaximumStackSize,
    PVOID AttributeList);

STARTUPINFOA si;
PROCESS_INFORMATION pi;
HANDLE hThread;

int main() {
    // Load NtCreateThreadEx
    HMODULE ntdll = GetModuleHandleA("ntdll.dll");
    NtCreateThreadExType NtCreateThreadEx = (NtCreateThreadExType)GetProcAddress(ntdll, "NtCreateThreadEx");
    if (!NtCreateThreadEx) {
        //printf("Failed to load NtCreateThreadEx\n");
        return -1;
    }

    // Step 1: Create a suspended target process (calc.exe)
    si.cb = sizeof(STARTUPINFOA);
    if (!CreateProcessA(NULL, (LPSTR)"powershell", NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi))
    {
        //printf("Failed to create process (error %d)\n", GetLastError());
        return -1;
    }

    //printf("Created calc.exe process with PID: %d\n", pi.dwProcessId);

    // Step 2: Allocate memory in the target process
    const char* cmdArgs = "Get-TimeZone";
    SIZE_T cmdArgsSize = lstrlenA(cmdArgs) + 1;
    LPVOID remoteMemory = VirtualAllocEx(pi.hProcess, NULL, cmdArgsSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!remoteMemory) {
        //printf("Failed to allocate memory in target process (error %d)\n", GetLastError());
        TerminateProcess(pi.hProcess, 1);
        return -1;
    }

    // Step 3: Write the command arguments into the allocated memory
    if (!WriteProcessMemory(pi.hProcess, remoteMemory, cmdArgs, cmdArgsSize, NULL)) {
        //printf("Failed to write memory in target process (error %d)\n", GetLastError());
        VirtualFreeEx(pi.hProcess, remoteMemory, 0, MEM_RELEASE);
        TerminateProcess(pi.hProcess, 1);
        return -1;
    }

    HMODULE kernel32 = GetModuleHandleA("kernel32.dll");
    FARPROC winExec = GetProcAddress(kernel32, "WinExec");

    // Step 4: Use NtCreateThreadEx to create a remote thread in the target process
    NTSTATUS status = NtCreateThreadEx(
        &hThread,
        THREAD_ALL_ACCESS,
        NULL,
        pi.hProcess,
        winExec, // Start routine (WinExec)
        remoteMemory, // Argument (command line arguments)
        FALSE,
        0,
        0,
        0,
        NULL
    );

    if (status < 0) {
        //printf("Failed to create remote thread (status 0x%x)\n", status);
        VirtualFreeEx(pi.hProcess, remoteMemory, 0, MEM_RELEASE);
        TerminateProcess(pi.hProcess, 1);
        return -1;
    }

    //printf("Successfully created remote thread. Resuming main process...\n");

    // Step 5: Resume the main process thread
    ResumeThread(pi.hThread);

    // Clean up
    WaitForSingleObject(hThread, INFINITE); // Wait for the thread to finish
    CloseHandle(hThread);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}