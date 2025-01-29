// Link      = https://attack.mitre.org/techniques/T1059/001/
// Technique = Command and Scripting Interpreter: PowerShell
// ID        = T1059.001
// Tactics   = Execution

#include <windows.h>
//#include <stdio.h>

#define RUN(toRun) WriteFile(hStdinWrite, toRun "\r\n", lstrlenA(toRun "\r\n"), &bytesWritten, NULL);

SECURITY_ATTRIBUTES sa;
PROCESS_INFORMATION pi;
STARTUPINFOA si;

int main() {
    HANDLE hStdinWrite, hStdinRead;
    HANDLE hStdoutWrite, hStdoutRead;
    char buffer[4096];
    DWORD bytesRead, bytesWritten;

    // Set security attributes for pipe handles
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.bInheritHandle = TRUE;
    sa.lpSecurityDescriptor = NULL;

    // Create pipes for standard input
    if (!CreatePipe(&hStdinRead, &hStdinWrite, &sa, 0)) {
        //printf("Failed to create stdin pipe.\n");
        return 1;
    }

    // Create pipes for standard output
    if (!CreatePipe(&hStdoutRead, &hStdoutWrite, &sa, 0)) {
        //printf("Failed to create stdout pipe.\n");
        return 1;
    }

    // Ensure the write handle to stdin and the read handle to stdout are not inherited
    SetHandleInformation(hStdinWrite, HANDLE_FLAG_INHERIT, 0);
    SetHandleInformation(hStdoutRead, HANDLE_FLAG_INHERIT, 0);

    // Set up STARTUPINFO to use the pipe handles
    si.cb = sizeof(si);
    si.hStdInput = hStdinRead;
    si.hStdOutput = hStdoutWrite;
    si.hStdError = hStdoutWrite;
    si.dwFlags |= STARTF_USESTDHANDLES;

    // Start the cmd.exe process
    if (!CreateProcessA(
        NULL,                    // Application name
        (LPSTR)"cmd.exe",               // Command line
        NULL,                    // Process handle not inheritable
        NULL,                    // Thread handle not inheritable
        TRUE,                    // Set handle inheritance to TRUE
        0,                       // No creation flags
        NULL,                    // Use parent's environment block
        NULL,                    // Use parent's starting directory
        &si,                     // Pointer to STARTUPINFO structure
        &pi))                    // Pointer to PROCESS_INFORMATION structure
    {
        //printf("Failed to create cmd.exe process (%d).\n", GetLastError());
        return 1;
    }

    // Close unused pipe ends
    CloseHandle(hStdinRead);
    CloseHandle(hStdoutWrite);

    RUN("powershell.exe Invoke-Command -ScriptBlock { runme.exe }");

    // Read the output from cmd.exe
    while (ReadFile(hStdoutRead, buffer, sizeof(buffer) - 1, &bytesRead, NULL) && bytesRead > 0) {
        buffer[bytesRead] = '\0'; // Null-terminate the buffer
        //printf("%s", buffer);
    }

    // Wait for cmd.exe process to exit
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Clean up
    CloseHandle(hStdinWrite);
    CloseHandle(hStdoutRead);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}