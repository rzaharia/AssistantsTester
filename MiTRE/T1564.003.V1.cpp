// Link      = https://attack.mitre.org/techniques/T1564/003/
// Technique = Hide Artifacts: Hidden Window
// ID        = T1564.003
// Tactics   = Defense Evasion

#include <windows.h>

int main() {
    ShellExecuteA(
        NULL,
        "open",
        "cmd.exe",
        "powershell.exe -WindowStyle Hidden a.ps1",
        NULL,
        SW_HIDE
    );

    return 0;
}




