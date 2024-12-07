// Link      = https://attack.mitre.org/techniques/T1083/
// Technique = File and Directory Discovery
// ID        = T1083
// Tactics   = Discovery

#include <windows.h>

int main() {
    ShellExecuteA(
        NULL,
        "open",
        "cmd.exe",
        "dir \"c:\\Program Files\\\" >> %temp%\\exported_data",
        NULL,
        SW_HIDE
    );

    return 0;
}

