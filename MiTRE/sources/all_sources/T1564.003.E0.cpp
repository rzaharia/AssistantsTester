// Link      = https://attack.mitre.org/techniques/T1564/003/
// Technique = Hide Artifacts: Hidden Window
// ID        = T1564.003
// Tactics   = Defense Evasion

#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("powershell.exe -WindowStyle Hidden a.ps1");
    return 0;
}