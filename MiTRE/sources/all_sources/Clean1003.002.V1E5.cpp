#include <windows.h>

#define RUN(toRun) WinExec(toRun, SW_SHOW);

int main() {
    RUN("reg sav HKLM\\system system");
    return 0;
}