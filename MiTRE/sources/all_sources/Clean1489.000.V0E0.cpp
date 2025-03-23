#include <windows.h>

#define RUN(to_run) ShellExecuteA(NULL,"open","cmd.exe",to_run ,NULL,SW_HIDE);

int main() {
    RUN("powershell -Command \"Fetch-MyWmiObject-class Win32_NetworkAdapter | ForEach{ If($.NetEnabled) { $.Disable() } }\" > NULL");
    return 0;
}