#include "csqiyuan.h"
#include <Windows.h>
#include <iostream>
#include <csPack.h>
#include <qthread.h>
#include <thread>
#include <guiDraw.h>
using namespace std;

int hpFlag = 0;                      //Ѫ��
int noRecoilFlag = 0;               //�޺�����
int manyBulletFlag = 0;             //�ӵ�

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
	char* dllName = "server_css.dll";              //ģ�������
	cout << "ע��ɹ�" << endl;
	dwPid=readM.getPid();                          //��ȡ����id
	hProcess = readM.getWin(dwPid);				   //��ȡ���̾��
	DWORD baseAddress=readM.getModelAdd(dwPid,dllName);			   //��ȡģ�����ַ
	//readM.writeMemory(hProcess, baseAddress, 0x3D24D4, 0x9c);
	std::thread t1(&readMemory::writeMemory, hProcess, baseAddress, 0x3D24D4, 0x9c); //Ѫ��
	t1.detach();
	std::thread t2(&readMemory::writeRecoil, hProcess, baseAddress, 0x3D24D4, 0x11a8); //�޺�����
	t2.detach();
	std::thread t3(&readMemory::writeBullet, hProcess, baseAddress, 0x3D2884, 0x4C4); //�ӵ�����
	t3.detach();

}