#include "pch.h"
#include "MainProc.h"

extern HINSTANCE hInst;

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
    // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
   
    /*SetPixel(hdc, 100, 100, RGB(255, 0, 0));
    SetPixel(hdc, 100, 105, RGB(0, 255, 0));
    SetPixel(hdc, 105, 100, RGB(0, 0, 255));*/
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

