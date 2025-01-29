// Link      = https://attack.mitre.org/techniques/T1124/
// Technique = System Time Discovery
// ID        = T1124.000
// Tactics   = Discovery

#include <windows.h>

#define RUN(toRun) WinExec("powershell -Command \"& { " toRun " }\"", SW_SHOW);

int main() {
    RUN("net time \\192.168.1.3 /set /yes");
    return 0;
}