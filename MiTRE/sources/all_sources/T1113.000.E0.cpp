// Link      = https://attack.mitre.org/techniques/T1113/
// Technique = Screen Capture
// ID        = T1113.000
// Tactics   = Collection

#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("snippingtool /clip");
    return 0;
}