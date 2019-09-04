#include <windows.h>

BOOL WINAPI DllMain (HANDLE hinstDLL, DWORD fwdReason, LPVOID lpvReserved)
{
  switch (fwdReason)
  {
    case DLL_PROCESS_ATTACH:
    dll_mll();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
    break;
  }
  
  return TRUE;

}

int dll_ml()
{
  MessageBox(0, "DLL HIJACKED!", "DLL Message", MB_OK);
}