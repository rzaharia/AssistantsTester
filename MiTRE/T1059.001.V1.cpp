// Link      = https://attack.mitre.org/techniques/T1059/001/
// Technique = Command and Scripting Interpreter: PowerShell
// ID        = T1059.001
// Tactics   = Execution,

#include <windows.h>


int main() {
    STARTUPINFOA si;
    si.cb = sizeof(STARTUPINFOA);
    PROCESS_INFORMATION pi;

    if (CreateProcessA(NULL,(LPSTR)"powershell.exe Start-Process -FilePath calc.exe",NULL,NULL,FALSE,CREATE_NO_WINDOW,NULL,NULL,&si,&pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    return 0;
}

