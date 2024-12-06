// Link      = https://attack.mitre.org/techniques/T1564/001/
// Technique = Hide Artifacts: Hidden Files and Directories
// ID        = T1564.001
// Tactics   = Defense Evasion

#include <windows.h>

int main() {
    ShellExecuteA(
        NULL,
        "open",
        "cmd.exe",
        "attrib +h C:\\temp\\x.exe",
        NULL,
        SW_HIDE
    );

    return 0;
}




