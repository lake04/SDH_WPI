#include "pch.h"
#include "MainProc.h"

extern HINSTANCE hInst;

int OnCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

int OnPaint(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
    TextOut(hdc, 100, 50, L"서울디지텍고등학교", 9);
    TextOut(hdc, 100, 70, L"게임프로그래밍전공", 9);
    TextOut(hdc, 100, 90, L"2학년1반 김정환", 9);
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

