// Link      = https://attack.mitre.org/techniques/T1113/
// Technique = Screen Capture
// ID        = T1113.000
// Tactics   = Collection

#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>

#define RUN(to_run) fprintf(batchFile, to_run "\n");

STARTUPINFOA si;
PROCESS_INFORMATION pi;

int main() {
    // Step 1: Write the command to a .bat file
    FILE* batchFile = fopen("example.bat", "w");
    if (!batchFile) {
        perror("Failed to create batch file");
        return 1;
    }

    // Write a command to the batch file
    fprintf(batchFile, "@echo off\n");
    fprintf(batchFile, "echo This command is inside a batch file!\n");

    RUN("snippingtool /clip");

    //fprintf(batchFile, "pause\n");
    fclose(batchFile);

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
    if (remove("example.bat") != 0) {
        perror("Failed to delete batch file");
    }

    return 0;
}