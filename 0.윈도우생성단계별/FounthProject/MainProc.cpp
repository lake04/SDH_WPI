#include "pch.h"
#include "MainProc.h"

extern HINSTANCE hInst;

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
    // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
    TextOut(hdc, 0, 0, L"�����ٶ󸶹ٻ�", 7);
    TextOut(hdc, 0, 20, L"������īŸ����", 7);
    TextOut(hdc, 0, 40, L"ABCDEFGHJKLMNOPQRSTUWXYZ", 23);

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

