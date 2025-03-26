// Link      = https://attack.mitre.org/techniques/T1136/001/
// Technique = Create Account: Local Account
// ID        = T1136.001
// Tactics   = Persistence

#include <windows.h>

#define RUN(toRun) WinExec(toRun, SW_SHOW);

int main() {
    RUN("net user /add abc");
    return 0;
}