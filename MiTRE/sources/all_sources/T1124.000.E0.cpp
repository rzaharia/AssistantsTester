// Link      = https://attack.mitre.org/techniques/T1124/
// Technique = System Time Discovery
// ID        = T1124.000
// Tactics   = Discovery

#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("net time \\192.168.1.3 /set /yes");
    return 0;
}