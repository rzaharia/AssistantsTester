// Link      = https://attack.mitre.org/techniques/T1113/
// Technique = Screen Capture
// ID        = T1113.000
// Tactics   = Collection

#include <windows.h>

#define RUN(toRun) WinExec(toRun, SW_SHOW);

int main() {
    RUN("snippingtool /clip");
    return 0;
}