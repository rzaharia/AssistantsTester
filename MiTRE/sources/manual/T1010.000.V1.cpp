// Link      = https://attack.mitre.org/techniques/T1010/
// Technique = Application Window Discovery
// ID        = T1010
// Tactics   = Discovery,

#include <windows.h>

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    char title[256];
    GetWindowTextA(hwnd, title, sizeof(title));
    return TRUE;
}

int main() {
    EnumWindows(EnumWindowsProc, 0);
    return 0;
}

