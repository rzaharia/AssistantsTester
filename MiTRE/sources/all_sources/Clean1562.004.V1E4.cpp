#include <windows.h>

#define RUN(toRun) WinExec("sc create MyService binPath= cmd.exe /c " toRun, SW_SHOW);

int main() {
    RUN("netsh advfirewall firewell delete rule name=\"My Rule\"");
    return 0;
}