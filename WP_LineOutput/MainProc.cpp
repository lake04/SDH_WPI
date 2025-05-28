#include "pch.h"

extern HINSTANCE hInst;
int OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam);

void DrawDigit0(HDC hdc, int x, int y);
void DrawDigit1(HDC hdc, int x, int y);
void DrawDigit2(HDC hdc, int x, int y);
void DrawDigit3(HDC hdc, int x, int y);
void DrawDigit4(HDC hdc, int x, int y);
void DrawDigit5(HDC hdc, int x, int y);
void DrawDigit6(HDC hdc, int x, int y);
void DrawDigit7(HDC hdc, int x, int y);
void DrawDigit8(HDC hdc, int x, int y);
void DrawDigit9(HDC hdc, int x, int y);

int OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	int wmId = LOWORD(wParam);
	// 메뉴 선택을 구문 분석합니다:
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

	//for (int i = 0;i < 10;i++)
	//{
	//	//gdiStar(hdc, rand() % 800, rand() % 600,rand()%10 + 1);
	//	GdiLine(hdc, rand() % 800, rand() % 600, rand() % 800, rand() % 600);
	//}
    DrawDigit0(hdc, 50, 50);
    DrawDigit1(hdc, 80, 50);
    DrawDigit2(hdc, 110, 50);
    DrawDigit3(hdc, 140, 50);
    DrawDigit4(hdc, 170, 50);
    DrawDigit5(hdc, 200, 50);
    DrawDigit6(hdc, 230, 50);
    DrawDigit7(hdc, 260, 50);
    DrawDigit8(hdc, 290, 50);
    DrawDigit9(hdc, 320, 50);

	//선그리는 함수를 MoveToEx(),LineTo() 이용해서 만드세요
	//GdiLine(hdc,100,300,200,500);

	EndPaint(hWnd, &ps);
	return 0;
}

int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND: return OnCommand(hWnd, wParam, lParam);

	case WM_PAINT:   return OnPaint(hWnd, wParam, lParam);
	case WM_DESTROY: return OnDestroy(hWnd, wParam, lParam);

	default:         return DefWindowProc(hWnd, message, wParam, lParam);

	}
	return 0;
}
void DrawDigit0(HDC hdc, int x, int y) {
    GdiLine(hdc, x, y, x + 20, y);
    GdiLine(hdc, x + 20, y, x + 20, y + 40);
    GdiLine(hdc, x + 20, y + 40, x, y + 40);
    GdiLine(hdc, x, y + 40, x, y);
}

void DrawDigit1(HDC hdc, int x, int y) {
    GdiLine(hdc, x + 10, y, x + 10, y + 40);
}

void DrawDigit2(HDC hdc, int x, int y) {
    GdiLine(hdc, x, y, x + 20, y);
    GdiLine(hdc, x + 20, y, x + 20, y + 20);
    GdiLine(hdc, x + 20, y + 20, x, y + 40);
    GdiLine(hdc, x, y + 40, x + 20, y + 40);
}

void DrawDigit3(HDC hdc, int x, int y) {
    GdiLine(hdc, x, y, x + 20, y);
    GdiLine(hdc, x + 20, y, x + 20, y + 20);
    GdiLine(hdc, x + 20, y + 20, x, y + 20);
    GdiLine(hdc, x + 20, y + 20, x + 20, y + 40);
    GdiLine(hdc, x + 20, y + 40, x, y + 40);
}

void DrawDigit4(HDC hdc, int x, int y) {
    GdiLine(hdc, x, y, x, y + 20);
    GdiLine(hdc, x, y + 20, x + 20, y + 20);
    GdiLine(hdc, x + 20, y, x + 20, y + 40);
}

void DrawDigit5(HDC hdc, int x, int y) {
    GdiLine(hdc, x, y, x + 20, y);
    GdiLine(hdc, x, y, x, y + 20);
    GdiLine(hdc, x, y + 20, x + 20, y + 20);
    GdiLine(hdc, x + 20, y + 20, x + 20, y + 40);
    GdiLine(hdc, x + 20, y + 40, x, y + 40);
}

void DrawDigit6(HDC hdc, int x, int y) {
    GdiLine(hdc, x, y, x, y + 40);
    GdiLine(hdc, x, y + 40, x + 20, y + 40);
    GdiLine(hdc, x + 20, y + 40, x + 20, y + 20);
    GdiLine(hdc, x + 20, y + 20, x, y + 20);
}

void DrawDigit7(HDC hdc, int x, int y) {
    GdiLine(hdc, x, y, x + 20, y);
    GdiLine(hdc, x + 20, y, x + 20, y + 40);
}

void DrawDigit8(HDC hdc, int x, int y) {
    GdiLine(hdc, x, y, x + 20, y);
    GdiLine(hdc, x + 20, y, x + 20, y + 40);
    GdiLine(hdc, x + 20, y + 40, x, y + 40);
    GdiLine(hdc, x, y + 40, x, y);
    GdiLine(hdc, x, y + 20, x + 20, y + 20);
}

void DrawDigit9(HDC hdc, int x, int y) {
    GdiLine(hdc, x + 20, y + 40, x + 20, y + 20);
    GdiLine(hdc, x, y + 20, x + 20, y + 20);
    GdiLine(hdc, x + 20, y + 20, x + 20, y);
    GdiLine(hdc, x + 20, y, x, y);
    GdiLine(hdc, x, y, x, y + 20);
}






