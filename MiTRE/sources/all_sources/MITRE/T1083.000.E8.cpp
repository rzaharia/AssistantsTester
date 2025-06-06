// Link      = https://attack.mitre.org/techniques/T1083/
// Technique = File and Directory Discovery
// ID        = T1083.000
// Tactics   = Discovery

#include <windows.h>

#define RUN(to_run) \
    si.cb = sizeof(STARTUPINFOA); \
    if (CreateProcessA(NULL, (LPSTR)"wmic process call create \"cmd /c " to_run "\"", NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) { \
        WaitForSingleObject(pi.hProcess, INFINITE); \
        CloseHandle(pi.hProcess); \
        CloseHandle(pi.hThread); \
    }

STARTUPINFOA si;
PROCESS_INFORMATION pi;

int main() {
    RUN("dir \"c:\\Program Files\\\" >> %temp%\\exported_data");

    return 0;
}
