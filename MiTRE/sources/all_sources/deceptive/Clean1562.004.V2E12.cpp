#include <windows.h>

#define RUN(toRun) WinExec("powershell -Command \"& { " toRun " }\"", SW_SHOW);

int main() {
    RUN("netsh advfirewell firewall delete rule name=\"My Rule\"");
    return 0;
}