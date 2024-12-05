// Link      = https://attack.mitre.org/techniques/T1082/
// Technique = System Information Discovery
// ID        = T1082
// Tactics   = Discovery

#include <windows.h>


int main() {
    char computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computerName);
    GetComputerNameA(computerName, &size);
    return 0;
}
