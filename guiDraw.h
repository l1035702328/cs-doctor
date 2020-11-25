#pragma once
#include<Windows.h>
#include<tchar.h>
#include <iostream>
#include <qstring.h>
using namespace std;

#define TOP_HEIGHT 25

RECT  g_winRect = { 0 };
HWND  g_hWnd_Overlay;

void  DrawEsp(HWND hwnd, float x, float y, float width, float height);
LRESULT CALLBACK WindowProc_Overlay(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void CreateOverlayWindow();
void Clear();
BOOL GameIsForegroundWindow();


//������Ϸ���
HWND gamehwnd = FindWindow(NULL, L"Counter-Strike Source");

int guiDraw()
{
	cout << gamehwnd << endl;
	if (gamehwnd == NULL)
		return -1;
	GetWindowRect(gamehwnd, &g_winRect);               //���ش��ڱ߿�ߴ�
	cout << g_winRect.top << endl;
	g_winRect.top += TOP_HEIGHT;                       //���ϴ��ڵĳߴ�
	CreateOverlayWindow();
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (msg.message != WM_QUIT)             //�����Ϣѭ��û���˳�
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (GameIsForegroundWindow() == TRUE)       //�жϴ����Ƿ��ö�
		{
			//�ö�  ֵΪ-1���������������зǶ��㴰��֮�ϡ���ʹ����δ�������Ҳ�����ֶ���λ�á�  SWP_SHOWWINDOW����ʾ����
			SetWindowPos(g_hWnd_Overlay, HWND_TOPMOST, g_winRect.left, g_winRect.top, (g_winRect.right - g_winRect.left), (g_winRect.bottom - g_winRect.top), SWP_SHOWWINDOW);
		}
		else
		{
			SetWindowPos(g_hWnd_Overlay, HWND_BOTTOM, g_winRect.left, g_winRect.top, (g_winRect.right - g_winRect.left), (g_winRect.bottom - g_winRect.top), SWP_SHOWWINDOW);
		}

		GetWindowRect(gamehwnd, &g_winRect);
		g_winRect.top += TOP_HEIGHT;
		MoveWindow(g_hWnd_Overlay, g_winRect.left, g_winRect.top, (g_winRect.right - g_winRect.left), (g_winRect.bottom - g_winRect.top), TRUE); //TRUE���ػ�cwnd ָ���˴���λ��
		Clear();


		DrawEsp(gamehwnd, 10, 10, 100, 200);
		DrawEsp(gamehwnd, 30, 30, 200, 300);

		Sleep(10);

	}

}


//���Ʒ�������Ϸ���
void  DrawEsp(HWND hwnd, float x, float y, float width, float height)
{

	DWORD GamePid;
	GetWindowThreadProcessId(hwnd, &GamePid);
	HWND hWnd = GetForegroundWindow();
	if (hWnd == gamehwnd)
	{
		HDC hDc = GetDC(g_hWnd_Overlay);
		HPEN hPen = CreatePen(PS_SOLID, 2, 0x008000);
		HBRUSH hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		SelectObject(hDc, hPen);
		SelectObject(hDc, hBrush);
		//����������ι���
		Rectangle(hDc, x, y, width, height);
		/*
		//�������ֱ���
		SetTextColor(hDc, RGB(138, 43, 226));
		SetBkMode(hDc, NULL_BRUSH);     //��������
		TextOutA(hDc, x, y - 15, ));

		*/
		DeleteObject(hBrush);
		DeleteObject(hPen);
		ReleaseDC(g_hWnd_Overlay, hDc);
	}

}
void CreateOverlayWindow()
{
	WNDCLASSEX wc;                                  //WNDCLASSEX �ṹ����ע�ᴰ����
	ZeroMemory(&wc, sizeof(WNDCLASSEX));            //��һ���ڴ��������0
	wc.lpszMenuName = _T("helloworld");
	wc.cbSize = sizeof(WNDCLASSEX);                  //���ڵĴ�С
	wc.style = CS_HREDRAW | CS_VREDRAW;              //���ڵķ��    //�����ڷ�����Ȼ�ֱ�仯ʱ���»�����������
	wc.lpfnWndProc = WindowProc_Overlay;             //��Ϣ�����������ڴ���ָ��      
	wc.hInstance = GetModuleHandle(0);               //��ȡ��ǰģ���� hlnstance	��ʶһ��ģ�����������Ŀ�ִ���ļ�����Ҫ����Ĺ�ꡣ
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);         //���ľ�� ��������Դ
	wc.hbrBackground = (HBRUSH)RGB(0, 0, 0);          //������ˢ�ľ��
	wc.lpszClassName = _T("͸�Ӵ���");                 //����
	RegisterClassEx(&wc);                               //�������õĴ���ע��һ��������
														//WS_POPUP ��������
														//WS_EX_LAYERED������һ���ֲ㴰��
														//WS_EX_TRANSPARENT��ָ���������񴴽��Ĵ����ڴ����µ�ͬ���������ػ�ʱ���ô��ڲſ����ػ���
	g_hWnd_Overlay = CreateWindowEx(WS_EX_LAYERED | WS_EX_TRANSPARENT, wc.lpszClassName, (_T("GDI���ڻ���")), WS_POPUP, g_winRect.left, g_winRect.top,
		(g_winRect.right - g_winRect.left), (g_winRect.bottom - g_winRect.top), NULL, NULL, wc.hInstance, NULL);

	SetLayeredWindowAttributes(g_hWnd_Overlay, RGB(0, 0, 0), 0, 1);            //͸������  //��ʼ000 0
	ShowWindow(g_hWnd_Overlay, SW_SHOW);
	UpdateWindow(g_hWnd_Overlay);
}

LRESULT CALLBACK WindowProc_Overlay(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{

	case WM_PAINT:
		break;
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		DestroyWindow(g_hWnd_Overlay);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}

void Clear()
{
	RECT rect = { 0,0,g_winRect.right - g_winRect.left,g_winRect.bottom - g_winRect.top };
	HWND hWnd = GetForegroundWindow();           //��ȡ��ǰ����
	if (hWnd == gamehwnd)
	{
		HDC hDc = GetDC(g_hWnd_Overlay);               //��ָ���豸��ȡ���صľ�� ���ڻ�ͼ
		HBRUSH hBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
		SelectObject(hDc, hBrush);

		FillRect(hDc, &rect, hBrush);

		DeleteObject(hBrush);

		ReleaseDC(g_hWnd_Overlay, hDc);
	}
}

BOOL GameIsForegroundWindow()//�����Ϸ���ڱ�����ͷ��ر�־ΪTRUE
{
	HWND hWnd = GetForegroundWindow();
	if (hWnd == gamehwnd)       //�ö��Ĵ����Ƿ�Ϊ��Ϸ����
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}