// Link      = https://attack.mitre.org/techniques/T1059/001/
// Technique = Command and Scripting Interpreter: PowerShell
// ID        = T1059.001
// Tactics   = Execution

#include <windows.h>

#define RUN(toRun) WinExec("sc create MyService binPath= cmd.exe /c " toRun, SW_SHOW);

int main() {
    RUN("powershell.exe Invoke-Command -ScriptBlock { runme.exe }");
    return 0;
}