// Link      = https://attack.mitre.org/techniques/T1614/001/
// Technique = System Location Discovery: System Language Discovery
// ID        = T1614.001
// Tactics   = Discovery

#include <windows.h>

int main() {
    DWORD count = GetKeyboardLayoutList(0, NULL);
    HKL list[1024];
    GetKeyboardLayoutList(count, list);

    return 0;
}


