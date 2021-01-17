#include <windows.h>
#include <cstdlib>

#include "patch_run_dll.h"

BOOL WINAPI DllMain(HMODULE hDLL, DWORD Reason, LPVOID Reserved) {
	switch(Reason) {
		case DLL_PROCESS_ATTACH:
			CreateThread(NULL, 0, &MyThread, NULL, 0, NULL);
		break;
		case DLL_THREAD_ATTACH:
		case DLL_PROCESS_DETACH:
		case DLL_THREAD_DETACH:
			break;
	}
	
    return TRUE;
}

DWORD WINAPI MyThread(void* v) {
	uintptr_t base_address;
	bool* static_run;
	
	// Get Base Adress of executable
	base_address = reinterpret_cast<uintptr_t>(GetModuleHandleA(0));
	
	// 
	static_run = reinterpret_cast<bool*>(base_address + 0x9F010);
	
	*static_run = false;
	
	return 0;
}