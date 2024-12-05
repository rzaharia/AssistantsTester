// Link      = https://attack.mitre.org/techniques/T1056/001/
// Technique = Input Capture: Keylogging
// ID        = T1056.001
// Tactics   = Collection, Credential Access

#include <windows.h>

HHOOK hKeyHook;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    return CallNextHookEx(hKeyHook, nCode, wParam, lParam);
}

int main() {
    SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(NULL), 0);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    UnhookWindowsHookEx(hKeyHook);
    return 0;
}
