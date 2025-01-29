// Link      = https://attack.mitre.org/techniques/T1082/
// Technique = System Information Discovery
// ID        = T1082.000
// Tactics   = Discovery

#include <windows.h>

#define RUN(toRun) WinExec("sc create MyService binPath= cmd.exe /c " toRun, SW_SHOW);

int main() {
    RUN("vssadmin list shadows");
    return 0;
}