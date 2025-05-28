#include "pch.h"

extern HINSTANCE hInst;

SYSTEMTIME gSt;

//WM_CREATE ���� �Լ� //�����찡 ������� �� �� ���� ȣ��
int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	SetTimer(hWnd,0,1000,NULL); //�ð� ���� ID(0��), 1000(1��)
	SendMessage(hWnd, WM_TIMER, NULL, NULL); //���� ���ϴ� �޽����� �����쿡�� ��Ź�ϴ� ����
	//OnCreate(hWand,NLII,NULL); //�� ���� ����
	return 0;  
}

//WM_TIMER ���� �Լ� //������ �ð����� �ݺ� ȣ��  //������ ���� ������
int OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	GetLocalTime(&gSt); //SYSTEMIME����ü ���� �� �����ϱ�
	TCHAR strYinme[128];
	SetWindowText( hWnd, strYinme);
	InvalidateRect(hWnd, NULL, NULL); // ��ȿȭ�������Ͽ�  wm_paintȣ��
	return 0;
}

int OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	int wmId = LOWORD(wParam);
	// �޴� ������ ���� �м��մϴ�:
	switch (wmId)
	{
	case IDM_ABOUT:
		DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		break;
	case IDM_EXIT:
		DestroyWindow(hWnd);
		break;
	default:
		return DefWindowProc(hWnd, WM_COMMAND, wParam, lParam);
	}
	return 0;
}
int OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);

	TCHAR strTime[128]; //���ڿ� //�ð�
	wsprintf(strTime,L"%d�� %d�� %d��",gSt.wHour,gSt.wMinute,gSt.wSecond); //���ڿ��� �ð� ����
	TextOut(hdc, 0, 0, strTime,wcslen(strTime));//�����쿡 ���� ���


	EndPaint(hWnd, &ps);
	return 0;
}

int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	KillTimer(hWnd, 0);
	PostQuitMessage(0);
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE: return OnCreate(hWnd, wParam, lParam);
		break;
	case WM_TIMER: return OnTimer(hWnd, wParam, lParam);
		break;
	case WM_COMMAND: return OnCommand(hWnd, wParam, lParam);

	case WM_PAINT:   return OnPaint(hWnd, wParam, lParam);
	case WM_DESTROY: return OnDestroy(hWnd, wParam, lParam);

	default:         return DefWindowProc(hWnd, message, wParam, lParam);

	}
	return 0;
}





