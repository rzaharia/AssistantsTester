// Link      = https://attack.mitre.org/techniques/T1083/
// Technique = File and Directory Discovery
// ID        = T1083
// Tactics   = Discovery

#include <windows.h>

int main() {
    WIN32_FIND_DATAA findFileData;
    HANDLE hFind;

    if ((hFind = FindFirstFileA("C:\\Program Files\\*.*", &findFileData)) == INVALID_HANDLE_VALUE) {
        return 1;
    }

    do {
        
    } while (FindNextFileA(hFind, &findFileData) != 0);

    FindClose(hFind);
    return 0;
}








