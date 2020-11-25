#include "csqiyuan.h"
#include <Windows.h>
#include <iostream>
#include <csPack.h>
#include <qthread.h>
#include <thread>
#include <guiDraw.h>
using namespace std;

int hpFlag = 0;                      //血量
int noRecoilFlag = 0;               //无后坐力
int manyBulletFlag = 0;             //子弹

csqiyuan::csqiyuan(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

csqiyuan::~csqiyuan()
{

}

void csqiyuan::on_checkBox_clicked(bool checked)
{
	if (checked == 1)
	{
		hpFlag = 1;
	}
	else
	{
		hpFlag = 0;
	}
}

void csqiyuan::on_checkBox_2_clicked(bool checked) 
{
	if(checked==1)
	{
		noRecoilFlag = 1;
	}
	else
	{
		noRecoilFlag = 0;
	}
}

void csqiyuan::on_checkBox_3_clicked(bool checked)
{
	if (checked == 1) 
	{
		manyBulletFlag = 1;
	}
	else
	{
		manyBulletFlag = 0;
	}
}
void csqiyuan::on_checkBox_4_clicked(bool checked)
{
	std::thread t3(guiDraw); //guiDraw();
	t3.detach();
}
void csqiyuan::on_zhuru_clicked()
{
	HANDLE hProcess;
	DWORD dwPid;
	readMemory readM;
	char* dllName = "server_css.dll";              //模块的名称
	cout << "注入成功" << endl;
	dwPid=readM.getPid();                          //获取进程id
	hProcess = readM.getWin(dwPid);				   //获取进程句柄
	DWORD baseAddress=readM.getModelAdd(dwPid,dllName);			   //获取模块基地址
	//readM.writeMemory(hProcess, baseAddress, 0x3D24D4, 0x9c);
	std::thread t1(&readMemory::writeMemory, hProcess, baseAddress, 0x3D24D4, 0x9c); //血量
	t1.detach();
	std::thread t2(&readMemory::writeRecoil, hProcess, baseAddress, 0x3D24D4, 0x11a8); //无后坐力
	t2.detach();
	std::thread t3(&readMemory::writeBullet, hProcess, baseAddress, 0x3D2884, 0x4C4); //子弹无限
	t3.detach();

}