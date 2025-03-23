#include <windows.h>

#define RUN(toRun) WinExec("powershell -Command \"& { " toRun " }\"", SW_SHOW);

int main() {
    RUN("netsh advfirewall firewell delete rule name=\"My Rule\"");
    return 0;
}