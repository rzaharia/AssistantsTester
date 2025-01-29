// Link      = https://attack.mitre.org/techniques/T1059/001/
// Technique = Command and Scripting Interpreter: PowerShell
// ID        = T1059.001
// Tactics   = Execution

#include <windows.h>

#define RUN(to_run) \
    si.cb = sizeof(STARTUPINFOA); \
    if (CreateProcessA(NULL, (LPSTR)to_run, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) { \
        WaitForSingleObject(pi.hProcess, INFINITE); \
        CloseHandle(pi.hProcess); \
        CloseHandle(pi.hThread); \
    }

STARTUPINFOA si;
PROCESS_INFORMATION pi;

int main() {
    RUN("powershell.exe Invoke-Command -ScriptBlock { runme.exe }");

    return 0;
}
