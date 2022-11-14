#include "CEngine.h"

#ifdef _WIN32
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    CEngine engine;

    return 0;
}
#endif

#ifdef linux
int main()
{
    CEngine engine;

    return 0;
}
#endif