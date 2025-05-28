#include "pch.h"
#include "MouseInput.h"

extern MouseMSG mousetState;
extern TCHAR strWheelValue[128];

int OnMouseWhell(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    int zDelta = GET_WHEEL_DELTA_WPARAM(wParam);
    wsprintf(strWheelValue, L"휠 회전값 : %3d", zDelta / WHEEL_DELTA);
    InvalidateRect(hWnd, NULL, TRUE);

    return 0;
}

//int OnMouseLBTNDBLCK(HWND hWnd, WPARAM wParam, LPARAM lParam, MouseMSG state)
//{
//    mousetState = state;
//    InvalidateRect(hWnd, NULL, TRUE);
//
//    return 0;
//}

int OnMouseLBTNDBLCK(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    mousetState = LDBLK;
    InvalidateRect(hWnd, NULL, TRUE);

    return 0;
}

int OnMouseRBTNDBLCK(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    mousetState = RDBLK;
    InvalidateRect(hWnd, NULL, TRUE);

    return 0;
}

int OnMouseMBTNDBLCK(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    mousetState = MDBLK;
    InvalidateRect(hWnd, NULL, TRUE);

    return 0;
}

int OnMouseLBUTTONDOWN(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    mousetState = LBD;
    InvalidateRect(hWnd, NULL, TRUE);

    return 0;
}

int OnMouseLBUTTONUP(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    mousetState = LBU;
    InvalidateRect(hWnd, NULL, TRUE);

    return 0;
}

int OnMouseRBUTTONDOMN(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    mousetState = RBD;
    InvalidateRect(hWnd, NULL, TRUE);

    return 0;
}

int OnMouseRBUTTONUP(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    mousetState = RBU;
    InvalidateRect(hWnd, NULL, TRUE);

    return 0;
}

int OnMouseMBUTTONDOWN(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    mousetState = MBD;
    InvalidateRect(hWnd, NULL, TRUE);

    return 0;
}

int OnMouseMBUTTONUP(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    mousetState = MBU;
    InvalidateRect(hWnd, NULL, TRUE);

    return 0;
}


