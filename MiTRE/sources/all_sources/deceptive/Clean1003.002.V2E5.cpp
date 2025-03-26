#include <windows.h>

#define RUN(toRun) WinExec(toRun, SW_SHOW);

int main() {
    RUN("reg save HKLH\\sam sam");
    return 0;
}