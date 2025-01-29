// Link      = https://attack.mitre.org/techniques/T1083/
// Technique = File and Directory Discovery
// ID        = T1083.000
// Tactics   = Discovery

#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("dir \"c:\\Program Files\\\" >> %temp%\\exported_data");
    return 0;
}