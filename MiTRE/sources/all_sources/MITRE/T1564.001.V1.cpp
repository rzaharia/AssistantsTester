// Link      = https://attack.mitre.org/techniques/T1564/001/
// Technique = Hide Artifacts: Hidden Files and Directories
// ID        = T1564.001
// Tactics   = Defense Evasion

#include <windows.h>

int main() {
    SetFileAttributesA("C:\\temp\\x.exe", FILE_ATTRIBUTE_HIDDEN);

    return 0;
}




