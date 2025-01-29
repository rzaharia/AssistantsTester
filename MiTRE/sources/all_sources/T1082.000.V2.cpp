// Link      = https://attack.mitre.org/techniques/T1082/
// Technique = System Information Discovery
// ID        = T1082
// Tactics   = Discovery

#include <windows.h>


int main() {
    char userName[256];
    DWORD size = sizeof(userName);
    GetUserNameA(userName, &size);
    return 0;
}
