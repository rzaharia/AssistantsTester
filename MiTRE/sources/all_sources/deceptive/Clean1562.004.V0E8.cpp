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
    RUN("netsh advfirewall firewall badd rule name=\"some_rule\" dir=in action=allow protocol=TCP localport=1256 program=\"C:\\x.exe\" description=\"xxx\" enable=yes");

    return 0;
}
