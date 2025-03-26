#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>

#define RUN(to_run) WriteFile(batchFile, (LPSTR)to_run, lstrlenA(to_run), &bytesWritten, NULL);

STARTUPINFOA si;
PROCESS_INFORMATION pi;

int main() {
    // Step 1: Write the command to a .bat file
     HANDLE batchFile = CreateFileA(
        "example.bat",
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    DWORD bytesWritten;
    WriteFile(batchFile, "@echo off\n", lstrlenA("@echo off\n"), &bytesWritten, NULL);
    WriteFile(batchFile, "echo This command is inside a batch file!\n", lstrlenA("echo This command is inside a batch file!\n"), &bytesWritten, NULL);

    RUN("net user /added abc");

    //fprintf(batchFile, "pause\n");
    CloseHandle(batchFile);

    // Step 2: Execute the batch file using CreateProcessA
    si.cb = sizeof(si);

    // Command to execute the batch file
    char command[] = "cmd /c example.bat";

    // Create process
    if (!CreateProcessA(
        NULL,             // Application name
        command,          // Command line
        NULL,             // Process handle not inheritable
        NULL,             // Thread handle not inheritable
        FALSE,            // Set handle inheritance to FALSE
        0,                // No creation flags
        NULL,             // Use parent's environment block
        NULL,             // Use parent's starting directory
        &si,              // Pointer to STARTUPINFO structure
        &pi))             // Pointer to PROCESS_INFORMATION structure
    {
        //printf("CreateProcessA failed (%d).\n", GetLastError());
        return 1;
    }

    // Wait until child process exits
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    // Clean up: Remove the batch file
    if (!DeleteFileA("example.bat")) {
        //perror("Failed to delete batch file");
    }

    return 0;
}