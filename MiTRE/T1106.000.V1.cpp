// Link      = https://attack.mitre.org/techniques/T1106/
// Technique = Native API
// ID        = T1106
// Tactics   = Execution,

#include <windows.h>

#include <windows.h>
#include <iostream>
#include <winternl.h>

typedef NTSTATUS(NTAPI* NtCreateProcess)(
    PHANDLE ProcessHandle,
    ACCESS_MASK DesiredAccess,
    POBJECT_ATTRIBUTES ObjectAttributes,
    HANDLE ParentProcess,
    BOOLEAN InheritObjectTable,
    HANDLE SectionHandle,
    HANDLE DebugPort,
    HANDLE ExceptionPort
    );

int main() {
    HMODULE ntdll = LoadLibraryA("ntdll.dll");
    NtCreateProcess pNtCreateProcess = (NtCreateProcess)GetProcAddress(ntdll, "NtCreateProcess");
    if (!pNtCreateProcess) {
        FreeLibrary(ntdll);
        return 1;
    }

    HANDLE parentProcess = GetCurrentProcess();
    HANDLE newProcessHandle = nullptr;
    if (pNtCreateProcess(&newProcessHandle,PROCESS_ALL_ACCESS,NULL,parentProcess,FALSE,NULL,NULL,NULL) != 0) {
        FreeLibrary(ntdll);
        return 1;
    }

    STARTUPINFOA si;
    si.cb = sizeof(STARTUPINFOA);
    PROCESS_INFORMATION pi;

    if (CreateProcessA("calc.exe",NULL,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi))
    {
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    CloseHandle(newProcessHandle);
    FreeLibrary(ntdll);

    return 0;
}
