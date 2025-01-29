// Link      = https://attack.mitre.org/techniques/T1614/001/
// Technique = System Location Discovery: System Language Discovery
// ID        = T1614.001
// Tactics   = Discovery

#include <windows.h>

int main() {
    LANGID l1 = GetUserDefaultLangID();
    LANGID l2 = GetSystemDefaultUILanguage();
    LANGID l3 = GetUserDefaultUILanguage();

    return 0;
}


