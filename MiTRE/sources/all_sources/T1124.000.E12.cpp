// Link      = https://attack.mitre.org/techniques/T1124/
// Technique = System Time Discovery
// ID        = T1124.000
// Tactics   = Discovery

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
    RUN("net time \\192.168.1.3 /set /yes");

    return 0;
}
