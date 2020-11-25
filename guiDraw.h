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


//定义游戏句柄
HWND gamehwnd = FindWindow(NULL, L"Counter-Strike Source");

int guiDraw()
{
	cout << gamehwnd << endl;
	if (gamehwnd == NULL)
		return -1;
	GetWindowRect(gamehwnd, &g_winRect);               //返回窗口边框尺寸
	cout << g_winRect.top << endl;
	g_winRect.top += TOP_HEIGHT;                       //加上窗口的尺寸
	CreateOverlayWindow();
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (msg.message != WM_QUIT)             //如果消息循环没有退出
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (GameIsForegroundWindow() == TRUE)       //判断窗口是否置顶
		{
			//置顶  值为-1，将窗口置于所有非顶层窗口之上。即使窗口未被激活窗口也将保持顶级位置。  SWP_SHOWWINDOW：显示窗口
			SetWindowPos(g_hWnd_Overlay, HWND_TOPMOST, g_winRect.left, g_winRect.top, (g_winRect.right - g_winRect.left), (g_winRect.bottom - g_winRect.top), SWP_SHOWWINDOW);
		}
		else
		{
			SetWindowPos(g_hWnd_Overlay, HWND_BOTTOM, g_winRect.left, g_winRect.top, (g_winRect.right - g_winRect.left), (g_winRect.bottom - g_winRect.top), SWP_SHOWWINDOW);
		}

		GetWindowRect(gamehwnd, &g_winRect);
		g_winRect.top += TOP_HEIGHT;
		MoveWindow(g_hWnd_Overlay, g_winRect.left, g_winRect.top, (g_winRect.right - g_winRect.left), (g_winRect.bottom - g_winRect.top), TRUE); //TRUE则重画cwnd 指定了窗口位置
		Clear();


		DrawEsp(gamehwnd, 10, 10, 100, 200);
		DrawEsp(gamehwnd, 30, 30, 200, 300);

		Sleep(10);

	}

}


//绘制方框传入游戏句柄
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
		//画出方框矩形功能
		Rectangle(hDc, x, y, width, height);
		/*
		//绘制文字备用
		SetTextColor(hDc, RGB(138, 43, 226));
		SetBkMode(hDc, NULL_BRUSH);     //设置字体
		TextOutA(hDc, x, y - 15, ));

		*/
		DeleteObject(hBrush);
		DeleteObject(hPen);
		ReleaseDC(g_hWnd_Overlay, hDc);
	}

}
void CreateOverlayWindow()
{
	WNDCLASSEX wc;                                  //WNDCLASSEX 结构用于注册窗口类
	ZeroMemory(&wc, sizeof(WNDCLASSEX));            //把一段内存的内容置0
	wc.lpszMenuName = _T("helloworld");
	wc.cbSize = sizeof(WNDCLASSEX);                  //窗口的大小
	wc.style = CS_HREDRAW | CS_VREDRAW;              //窗口的风格    //当窗口发生宽度或垂直变化时重新绘制整个窗口
	wc.lpfnWndProc = WindowProc_Overlay;             //消息处理函数，窗口处理指针      
	wc.hInstance = GetModuleHandle(0);               //获取当前模块句柄 hlnstance	标识一个模块事例，它的可执行文件包含要载入的光标。
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);         //光标的句柄 载入光标资源
	wc.hbrBackground = (HBRUSH)RGB(0, 0, 0);          //背景画刷的句柄
	wc.lpszClassName = _T("透视窗口");                 //类名
	RegisterClassEx(&wc);                               //在随后调用的窗口注册一个窗口类
														//WS_POPUP 弹出窗口
														//WS_EX_LAYERED：创建一个分层窗口
														//WS_EX_TRANSPARENT：指定以这个风格创建的窗口在窗口下的同属窗口已重画时，该窗口才可以重画。
	g_hWnd_Overlay = CreateWindowEx(WS_EX_LAYERED | WS_EX_TRANSPARENT, wc.lpszClassName, (_T("GDI窗口绘制")), WS_POPUP, g_winRect.left, g_winRect.top,
		(g_winRect.right - g_winRect.left), (g_winRect.bottom - g_winRect.top), NULL, NULL, wc.hInstance, NULL);

	SetLayeredWindowAttributes(g_hWnd_Overlay, RGB(0, 0, 0), 0, 1);            //透明窗口  //初始000 0
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
	HWND hWnd = GetForegroundWindow();           //获取当前窗口
	if (hWnd == gamehwnd)
	{
		HDC hDc = GetDC(g_hWnd_Overlay);               //在指定设备提取返回的句柄 用于画图
		HBRUSH hBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
		SelectObject(hDc, hBrush);

		FillRect(hDc, &rect, hBrush);

		DeleteObject(hBrush);

		ReleaseDC(g_hWnd_Overlay, hDc);
	}
}

BOOL GameIsForegroundWindow()//如果游戏窗口被激活。就返回标志为TRUE
{
	HWND hWnd = GetForegroundWindow();
	if (hWnd == gamehwnd)       //置顶的窗口是否为游戏窗口
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}