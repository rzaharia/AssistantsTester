// Link      = https://attack.mitre.org/techniques/T1082/
// Technique = System Information Discovery
// ID        = T1082
// Tactics   = Discovery

#include <windows.h>

int main() {
    ShellExecuteA(
        NULL,
        "open",
        "cmd.exe",
        "ver >> %temp%\\download",
        NULL,
        SW_HIDE
    );


    return 0;
}
