#include <windows.h>
#include <cstdlib>

#include "simple_dll.h"

BOOL WINAPI DllMain(HMODULE hDLL, DWORD Reason, LPVOID Reserved) {
	switch(Reason) {
		case DLL_PROCESS_ATTACH:
			MessageBox(NULL, "Hello", "Hello", MB_OK);
		break;
		case DLL_THREAD_ATTACH:
		case DLL_PROCESS_DETACH:
		case DLL_THREAD_DETACH:
			break;
	}
	
    return TRUE;
}

