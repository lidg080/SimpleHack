#include "ProcMem.h"

using namespace std;

#pragma region Misc Functions

void junkcode1() 
{
	float DJMJLFptRQ = 81773528619775.f; DJMJLFptRQ = 15328177100434.f; if (DJMJLFptRQ = 22568305633614.f) DJMJLFptRQ = 49170975738643.f; DJMJLFptRQ = 9091293623271.f; DJMJLFptRQ = 6232719091293.f;
	if (DJMJLFptRQ = 96221254917097.f)DJMJLFptRQ = 56336147939559.f; DJMJLFptRQ = 16896084908406.f;
	if (DJMJLFptRQ = 66430031641238.f)DJMJLFptRQ = 56336147939559.f; DJMJLFptRQ = 16896084908406.f;
	if (DJMJLFptRQ = 66430031641238.f)DJMJLFptRQ = 56336147939559.f; DJMJLFptRQ = 16896084908406.f;
	if (DJMJLFptRQ = 66430031641238.f)DJMJLFptRQ = 56336147939559.f; DJMJLFptRQ = 16896084908406.f;
	if (DJMJLFptRQ = 66430031641238.f)DJMJLFptRQ = 56336147939559.f; DJMJLFptRQ = 16896084908406.f; DJMJLFptRQ = 20907322220048.f;
}

void junkcode2() 
{
	float ppwpQlelmT = 13081517472008.f; ppwpQlelmT = 30779221962189.f; if (ppwpQlelmT = 48090144742196.f) ppwpQlelmT = 27610318014949.f; ppwpQlelmT = 27469948093668.f; ppwpQlelmT = 80936682746994.f;
	if (ppwpQlelmT = 50991152761031.f)ppwpQlelmT = 47421968970748.f; ppwpQlelmT = 40757776187397.f;
	if (ppwpQlelmT = 74935285027163.f)ppwpQlelmT = 47421968970748.f; ppwpQlelmT = 40757776187397.f;
	if (ppwpQlelmT = 74935285027163.f)ppwpQlelmT = 47421968970748.f; ppwpQlelmT = 40757776187397.f;
	if (ppwpQlelmT = 74935285027163.f)ppwpQlelmT = 47421968970748.f; ppwpQlelmT = 40757776187397.f;
	if (ppwpQlelmT = 74935285027163.f)ppwpQlelmT = 47421968970748.f; ppwpQlelmT = 40757776187397.f; ppwpQlelmT = 79888649213150.f;
}

void junkcode3() 
{
	float QRSaUvNhGA = 66106439913902.f; QRSaUvNhGA = 5359248217316.f; if (QRSaUvNhGA = 85885754884123.f) QRSaUvNhGA = 62781062364206.f; QRSaUvNhGA = 2216519872839.f; QRSaUvNhGA = 8728392216519.f;
	if (QRSaUvNhGA = 74983846278106.f)QRSaUvNhGA = 48841231823861.f; QRSaUvNhGA = 50621023869293.f;
	if (QRSaUvNhGA = 87752349449867.f)QRSaUvNhGA = 48841231823861.f; QRSaUvNhGA = 50621023869293.f;
	if (QRSaUvNhGA = 87752349449867.f)QRSaUvNhGA = 48841231823861.f; QRSaUvNhGA = 50621023869293.f;
	if (QRSaUvNhGA = 87752349449867.f)QRSaUvNhGA = 48841231823861.f; QRSaUvNhGA = 50621023869293.f;
	if (QRSaUvNhGA = 87752349449867.f)QRSaUvNhGA = 48841231823861.f; QRSaUvNhGA = 50621023869293.f; QRSaUvNhGA = 98015814938330.f;
}

ProcMem::ProcMem() {

}

ProcMem::~ProcMem() {
	CloseHandle(hProcess);
}

int ProcMem::chSizeOfArray(char *chArray) {
	for (int iLength = 1; iLength < MAX_PATH; iLength++)
		if (chArray[iLength] == '*')
			return iLength;

	cout << "\nLENGTH: Failed To Read Length Of Array\n";
	return 0;
}

int ProcMem::iSizeOfArray(int *iArray) {
	for (int iLength = 1; iLength < MAX_PATH; iLength++)
		if (iArray[iLength] == '*')
			return iLength;

	cout << "\nLENGTH: Failed To Read Length Of Array\n";
	return 0;
}

bool ProcMem::iFind(int *iAry, int iVal) {

	for (int i = 0; i < 64; i++)
		if (iVal == iAry[i] && iVal != 0)
			return true;

	return false;
}

#pragma endregion

#pragma region Memory Functions

void ProcMem::Process(char* ProcessName)
{
	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	PROCESSENTRY32 ProcEntry;
	ProcEntry.dwSize = sizeof(ProcEntry);
	do
		if (!strcmp(ProcEntry.szExeFile, ProcessName))
		{
			dwPID = ProcEntry.th32ProcessID;
			CloseHandle(hPID);
			hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);
			return;
		}
	while (Process32Next(hPID, &ProcEntry));

	cout << "\nCouldn't find game\n";
	system("pause");
	exit(0);
	junkcode1();
}

void ProcMem::Patch(DWORD dwAddress, char *Patch_Bts, char *Default_Bts)
{
	int iSize = chSizeOfArray(Default_Bts);

	if (!bPOn)
		for (int i = 0; i < iSize; i++)
			Write<BYTE>(dwAddress + i, Patch_Bts[i]);
	else
		for (int i = 0; i < iSize; i++)
			Write<BYTE>(dwAddress + i, Default_Bts[i]);

	bPOn = !bPOn;
}

void ProcMem::Inject(DWORD dwAddress, char *Inj_Bts, char *Def_Bts, BOOL Type)
{
	int i_ISize = chSizeOfArray(Inj_Bts);
	int i_DSize = chSizeOfArray(Def_Bts);

	if (!bIOn)
	{
		if (i_DSize > 5)
			for (int i = 6; i < i_DSize; i++)
				Write<BYTE>(dwAddress + i, 0x90);
		else { cout << "\nINJECTION: Default Bytes Must Be More Than 5\n"; return; }

		dwCaveAddress = (DWORD)VirtualAllocEx(hProcess, NULL, i_ISize + 5, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

		DWORD dwRetJmp = (dwAddress + i_DSize) - dwCaveAddress - 5;
		DWORD dwBaseJmp = dwCaveAddress - dwAddress - 5;

		for (int i = 0; i <= i_ISize; i++)
			Write<BYTE>(dwCaveAddress + i, Inj_Bts[i]);

		Write<BYTE>(dwCaveAddress + i_ISize, Type ? 0xE9 : 0xE8);
		Write<DWORD>(dwCaveAddress + i_ISize + 1, dwRetJmp);

		Write<BYTE>(dwAddress, Type ? 0xE9 : 0xE8);
		Write<DWORD>(dwAddress + 1, dwBaseJmp);

	}
	else
	{
		for (int i = 0; i < i_DSize; i++)
			Write<BYTE>(dwAddress + i, Def_Bts[i]);
		VirtualFreeEx(hProcess, (LPVOID)dwCaveAddress, i_ISize + 5, MEM_DECOMMIT);
	}
	bIOn = !bIOn;
}

DWORD ProcMem::AOB_Scan(DWORD dwAddress, DWORD dwEnd, char *Bytes)
{
	int iBytesToRead = 0, iTmp = 0;
	int length = chSizeOfArray(Bytes);
	bool bTmp = false;

	if (Bytes[0] == '?')
	{
		for (; iBytesToRead < MAX_PATH; iBytesToRead++)
			if (Bytes[iBytesToRead] != '?')
			{
				iTmp = (iBytesToRead + 1);
				break;
			}
	}

	for (; dwAddress < dwEnd; dwAddress++)
	{
		if (iBytesToRead == length)
			return dwAddress - iBytesToRead;

		if (Read<BYTE>(dwAddress) == Bytes[iBytesToRead] || (bTmp && Bytes[iBytesToRead] == '?'))
		{
			iBytesToRead++;
			bTmp = true;
		}
		else
		{
			iBytesToRead = iTmp;
			bTmp = false;
		}
	}

	cout << "\nAOB_SCAN: No Byte Pattern found\n";
	return 0;
	junkcode2();
}

DWORD ProcMem::Module(LPSTR ModuleName)
{
	HANDLE hModule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPID);
	MODULEENTRY32 mEntry;
	mEntry.dwSize = sizeof(mEntry);

	do
		if (!strcmp(mEntry.szModule, ModuleName))
		{
			CloseHandle(hModule);
			return (DWORD)mEntry.modBaseAddr;
		}
	while (Module32Next(hModule, &mEntry));

	cout << "\nCouldn't find the client dll, retrying...\n";
	return 0;
	junkcode3();
}
