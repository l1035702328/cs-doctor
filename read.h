#pragma once
#include <Windows.h>
#include <iostream>
#include <qmessagebox.h>
using namespace std;

class readmemory
{
public:
	HWND getWin()
	{
		DWORD dwPID = 0;
		HWND getmy = FindWindow(NULL, L"Counter-Strike Source");
		if(getmy==NULL)
		{
			QMessageBox::information(NULL, "Title", QString::fromLocal8Bit("��ȡ���ھ��ʧ��"));
			return 0;
		}
		else
		{
			QMessageBox::information(NULL, "Title", QString::fromLocal8Bit("��ȡ�ɹ�"));
			GetWindowThreadProcessId(getmy, &dwPID);                                             //��ȡ����pid
			if(dwPID==0)
			{
				QMessageBox::information(NULL, "Title", QString::fromLocal8Bit("���̻�ȡʧ��"));
				return 0;
			}
			else
			{

			}
		}
	}
};