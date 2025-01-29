// Link      = https://attack.mitre.org/techniques/T1614/001/
// Technique = System Location Discovery: System Language Discovery
// ID        = T1614.001
// Tactics   = Discovery

#include <windows.h>

int main() {
    HKEY hKey;
    char defaultValue[256]; 
    DWORD bufferSize = sizeof(defaultValue);

    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\Nls\\Language", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        RegQueryValueExA(hKey, NULL, NULL, NULL, (LPBYTE)defaultValue, &bufferSize);
        RegCloseKey(hKey);
    }

    return 0;
}


