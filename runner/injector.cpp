#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <vector>
#include <string>
#include <Psapi.h>

using namespace std;

vector<DWORD> getPIDs(string process_name)
{
	vector<DWORD> pids;
	wstring targetProcessName(process_name.begin(), process_name.end());
	HANDLE snap;
	PROCESSENTRY32W entry;
	
	// Create Snapshot
	snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	
	// Set entry size
	entry.dwSize = sizeof entry;

	//start with the first in snapshot
	if(Process32FirstW(snap, &entry))
	{
		do
		{
			//if name matches add to the list
			if (wstring(entry.szExeFile) == targetProcessName)
			{
				pids.emplace_back(entry.th32ProcessID);
			}
		}
		while (Process32NextW(snap, &entry)); //keep going until end of snapshot
	}
	
	return pids;
}

vector<DWORD> waitForRunner()
{
	vector<DWORD> pids;
	
	while(pids.size() == 0)
	{
		pids = getPIDs("runner.exe");
	}
	
	return pids;
}

uint64_t GetBaseAddress(const HANDLE handle)
{
	// Array that receives the list of module handles
	HMODULE modules[1024];
	// Output of EnumProcessModules, giving the number of bytes requires to store all modules handles in the lphModule array
	DWORD lpcbNeeded;
	TCHAR szModName[MAX_PATH];
	
	if(handle == NULL)
	{
		return 0; // No access to the process
	}
	
	if (!EnumProcessModules(handle, modules, sizeof(modules), &lpcbNeeded))
	{
		return 0; // Impossible to read modules
	}
	
	if (!GetModuleFileNameEx(handle, modules[0], szModName, sizeof(szModName) / sizeof(TCHAR)))
	{
		return 0; // Impossible to get module info
	}
	
	// Module 0 is always the EXE itself, returning its address
	return (uint64_t)modules[0];
}

HANDLE getHandler(DWORD pid)
{
	HANDLE handle;
	
	handle = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
	
	if (handle == NULL)
	{
		cout << "[Error]: Failed to create handle." << endl;
		
		return NULL;
	}
	
	return handle;
}

size_t read_data(HANDLE handle, uint64_t adress, vector<unsigned char> &buffer, size_t size)
{
	size_t read_size;
	
	buffer.resize(size);
	
	ReadProcessMemory(handle, (LPCVOID)(adress), &buffer[0], size, &read_size);
	
	buffer.resize(read_size);
	
	return read_size;
}

void printVector(const string &name, vector<unsigned char> &buffer)
{
	cout << name << " = { ";
	for(unsigned char c : buffer)
	{
		cout << std::hex << (int)c << " ";
	}
	cout << "}" << endl;
}

void patch_jmp(HANDLE handle, uint64_t base_adress)
{
	vector<unsigned char> buffer, patch;
	
	patch = { 0x90, 0x90 };
	
	// Read memory buffer and show in console
	read_data(handle, base_adress + 0x158A, buffer, 2);	
	printVector("[*] buffer", buffer);
	
	cout << "[*] Patching jmp assembly" << endl;
	
	// Patch assembly with NOP
	WriteProcessMemory(handle, (LPVOID)(base_adress + 0x158A), &patch[0], 2, nullptr);
	
	cout << "[*] Done!" << endl;
}

void patch_static_run(HANDLE handle, uint64_t base_adress)
{
	vector<unsigned char> buffer, patch;
	
	patch = { 0x00 };
	
	// Read memory buffer and show in console
	read_data(handle, base_adress + 0x9F010, buffer, 1);	
	printVector("[*] buffer", buffer);
	
	cout << "[*] Patching static run variable" << endl;
	
	// Patch static run variable
	WriteProcessMemory(handle, (LPVOID)(base_adress + 0x9F010), &patch[0], 2, nullptr);
	
	cout << "[*] Done!" << endl;
}

int main(int, char *[])
{
	vector<DWORD> pids;
	HANDLE handle;
	uint64_t base_adress;
	
	// Wait for runner.exe
	cout << "[*] Waiting for runner.exe" << endl;
	pids = waitForRunner();
	
	// Show runner.exe pid's
	for (DWORD pid : pids) {
		cout <<	"[*] Found runner.exe [PID:" << pid << "]" << endl;
		
		handle = getHandler(pid);
		base_adress = GetBaseAddress(handle);
		
		//patch_jmp(handle, base_adress);
		patch_static_run(handle, base_adress);
		
		CloseHandle(handle);
	}
	
	system("pause");
}