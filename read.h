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
			QMessageBox::information(NULL, "Title", QString::fromLocal8Bit("获取窗口句柄失败"));
			return 0;
		}
		else
		{
			QMessageBox::information(NULL, "Title", QString::fromLocal8Bit("获取成功"));
			GetWindowThreadProcessId(getmy, &dwPID);                                             //获取进程pid
			if(dwPID==0)
			{
				QMessageBox::information(NULL, "Title", QString::fromLocal8Bit("进程获取失败"));
				return 0;
			}
			else
			{

			}
		}
	}
};