#pragma once
#include <Windows.h>
#include <iostream>
#include <qstring.h>
#include <qmessagebox.h>
#include <TlHelp32.h>
#include <thread>
extern int hpFlag;
extern int noRecoilFlag;
extern int manyBulletFlag;
using namespace std;

inline char* UnicodeToAnsi(const wchar_t* szStr)
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, szStr, -1, NULL, 0, NULL, NULL);
	if (nLen == 0)
	{
		return NULL;
	}
	char* pResult = new char[nLen];
	WideCharToMultiByte(CP_ACP, 0, szStr, -1, pResult, nLen, NULL, NULL);
	return pResult;
}

PVOID GetProcessImageBase(DWORD dwProcessId, char* dllName)
{
	PVOID pProcessImageBase = NULL;
	MODULEENTRY32 me32 = { 0 };
	me32.dwSize = sizeof(MODULEENTRY32);
	char buf1[1000];
	sprintf(buf1, "%d", me32.dwSize);
	QMessageBox::information(NULL, "Title", buf1);
	// ��ȡָ������ȫ��ģ��Ŀ���
	HANDLE hModuleSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwProcessId);
	if (INVALID_HANDLE_VALUE == hModuleSnap)
	{
		return pProcessImageBase;
	}
	// ��ȡ�����е�һ����Ϣ
	BOOL bRet = ::Module32First(hModuleSnap, &me32);
	cout << hModuleSnap << endl;
	//֮�����Ϣ
	while (strcmp(UnicodeToAnsi(me32.szModule), dllName) != 0)
	{
		char* mystr = UnicodeToAnsi(me32.szModule);
		cout << mystr << endl;
		Module32Next(hModuleSnap, &me32);
	}
	pProcessImageBase = (PVOID)me32.modBaseAddr;
	// �رվ��
	::CloseHandle(hModuleSnap);
	return pProcessImageBase;
}


class readMemory
{
public:
	DWORD getPid()
	{
		DWORD dwPid = 0;          //��ȡpid
		HWND getmy = FindWindow(NULL, L"Counter-Strike Source");
		if (getmy == NULL)
		{
			QMessageBox::information(NULL, "Title", QString::fromLocal8Bit("��ȡ���ھ��ʧ��"));
			return 0;
		}
		else
		{
			GetWindowThreadProcessId(getmy, &dwPid);  //���ݸ�dwPID
			if (dwPid == 0)
			{
				QMessageBox::information(NULL, "Title", QString::fromLocal8Bit("����ID��ȡʧ��"));
				return 0;
			}
			else
			{
				return dwPid;
			}
		}

	};
	HANDLE getWin(DWORD dwPid)
	{
		cout << dwPid << endl;
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, dwPid);
		if (hProcess == NULL)
		{ 
			int ret = GetLastError();
			cout << ret<< endl;
			QMessageBox::information(NULL, "Title", QString::fromLocal8Bit("���̴�ʧ��"));
			return 0;
		}
		else
		{
			return hProcess;
		}
	};
	DWORD getModelAdd(DWORD pid,char* dllName)          //��ģ��Ļ�ַ
	{ 
		DWORD baseAddress;
		baseAddress = (DWORD)GetProcessImageBase(pid, dllName);
		return baseAddress;
	};
	static void writeMemory(HANDLE hProcess,DWORD baseAddress,DWORD offset ,DWORD one) 
	{
		DWORD oneOffsetValue;
		DWORD twoOffsetValue;
		ULONG_PTR dwsize = 0;
		if (ReadProcessMemory(hProcess, (LPVOID)(baseAddress + offset), &oneOffsetValue, sizeof(DWORD), &dwsize) != 0)
		{
			if(one!=0)
			{
				if (ReadProcessMemory(hProcess, (LPVOID)(oneOffsetValue+one), &twoOffsetValue, sizeof(DWORD), &dwsize) != 0) 
				{
					cout << twoOffsetValue << endl;
					int csHp = 300;
					while (1)
					{
						cout << hpFlag << endl;
						if (hpFlag == 1)
						{
							WriteProcessMemory(hProcess, (LPVOID)(oneOffsetValue + one), &csHp, sizeof(DWORD), &dwsize);
							Sleep(500);
						}
						else
						{
							return;
						}
					}
				}
			}

		}
	};
	static void writeRecoil(HANDLE hProcess, DWORD baseAddress, DWORD offset, DWORD one)
	{
		DWORD oneOffsetValue;
		DWORD twoOffsetValue;
		ULONG_PTR dwsize = 0;
		if (ReadProcessMemory(hProcess, (LPVOID)(baseAddress + offset), &oneOffsetValue, sizeof(DWORD), &dwsize) != 0)
		{
			if (one != 0)
			{
				if (ReadProcessMemory(hProcess, (LPVOID)(oneOffsetValue + one), &twoOffsetValue, sizeof(DWORD), &dwsize) != 0)
				{
					cout << twoOffsetValue << endl;
					int recoil = 0;
					while (1)
					{
						cout << twoOffsetValue << endl;
						if (noRecoilFlag == 1)
						{
							WriteProcessMemory(hProcess, (LPVOID)(oneOffsetValue + one), &recoil, sizeof(DWORD), &dwsize);
							Sleep(30);
						}
						else
						{
							return;
						}
					}
				}
			}

		}
	};
	static void writeBullet(HANDLE hProcess, DWORD baseAddress, DWORD offset, DWORD one)
	{
		DWORD oneOffsetValue;
		DWORD twoOffsetValue;
		ULONG_PTR dwsize = 0;
		if (ReadProcessMemory(hProcess, (LPVOID)(baseAddress + offset), &oneOffsetValue, sizeof(DWORD), &dwsize) != 0)
		{
			if (one != 0)
			{
				if (ReadProcessMemory(hProcess, (LPVOID)(oneOffsetValue + one), &twoOffsetValue, sizeof(DWORD), &dwsize) != 0)
				{
					cout << twoOffsetValue << endl;
					int bullet = 30;
					while (1)
					{
						cout << twoOffsetValue << endl;
						if (manyBulletFlag == 1)
						{
							WriteProcessMemory(hProcess, (LPVOID)(oneOffsetValue + one), &bullet, sizeof(DWORD), &dwsize);
							Sleep(30);
						}
						else
						{
							return;
						}
					}
				}
			}

		}
	};



};