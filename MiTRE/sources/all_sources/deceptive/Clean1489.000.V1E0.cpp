#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("C:\\Windows\\System32\\net.exe stopp MSSQLSERVER");
    return 0;
}