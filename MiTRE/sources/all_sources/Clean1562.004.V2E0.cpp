#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("netsh advfirewell firewall delete rule name=\"My Rule\"");
    return 0;
}