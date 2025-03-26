// Link      = https://attack.mitre.org/techniques/T1003/001/
// Technique = OS Credential Dumping: LSASS Memory
// ID        = T1003.001
// Tactics   = Credential Access

#include <windows.h>

DWORD get_process_pid(const char * name) {
    // not a valid pid - a pid should be divisible by 4
    return 1111;
}
int main() {
    HANDLE hProcess = OpenProcess(PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, FALSE, get_process_pid("lsass.exe"));
    if (!hProcess) {
        return 0;
    }

    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    MEMORY_BASIC_INFORMATION memInfo;

    auto ptr = (BYTE*)sysInfo.lpMinimumApplicationAddress;
    if (VirtualQueryEx(hProcess, ptr, &memInfo, sizeof(memInfo)) == sizeof(memInfo)) {
        if (memInfo.State == MEM_COMMIT && (memInfo.Type == MEM_PRIVATE || memInfo.Type == MEM_IMAGE)) {
            BYTE buffer[4096];
            SIZE_T bytesRead;

            ReadProcessMemory(hProcess, ptr, buffer, memInfo.RegionSize, &bytesRead);
        }
    }
    CloseHandle(hProcess);

    return 0;
}

