// Link      = https://attack.mitre.org/techniques/T1564/001/
// Technique = Hide Artifacts: Hidden Files and Directories
// ID        = T1564.001
// Tactics   = Defense Evasion

#include <windows.h>

#define RUN(toRun) WinExec(toRun, SW_SHOW);

int main() {
    RUN("attrib +h C:\\temp\\x.exe");
    return 0;
}