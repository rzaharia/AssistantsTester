// Link      = https://attack.mitre.org/techniques/T1562/004/
// Technique = Impair Defenses: Disable or Modify System Firewall
// ID        = T1562.004
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
    RUN("netsh advfirewall firewall delete rule name=\"My Rule\"");

    return 0;
}
