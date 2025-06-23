#include "pch.h"
#include "MainProc.h"

extern HINSTANCE hInst;

int OnCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

int OnPaint(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
    TextOut(hdc, 100, 50, L"��������ذ���б�", 9);
    TextOut(hdc, 100, 70, L"�������α׷�������", 9);
    TextOut(hdc, 100, 90, L"2�г�1�� ����ȯ", 9);
    EndPaint(hWnd, &ps);

    return 0;
}

int OnDestroy(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PostQuitMessage(0);

    return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        return OnCommand(hWnd,message,wParam,lParam);
    }
    break;
    case WM_PAINT:
    {
        return OnPaint(hWnd, message, wParam, lParam);
    }
    break;
    case WM_DESTROY:
        OnDestroy(hWnd, message, wParam, lParam);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

