#include "pch.h"
#include "MainProc.h"

extern HINSTANCE hInst;

extern MouseMSG mousetState;
extern TCHAR strWheelValue[128];

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
    TextOut(hdc, 10, 30, strWheelValue, wcslen(strWheelValue)); //휠

    Ellipse(hdc,100,100,300,500);
    Rectangle(hdc, 130, 150, 180, 250);
    Rectangle(hdc, 220, 150, 270, 250);
    Ellipse(hdc, 180, 160, 220, 240);

    HBRUSH holdBr, hMyBr;

    switch (mousetState)
    {
    case MouseMSG::LDBLK:
        TextOut(hdc, 10, 10, L"마우스 왼쪽 버튼 더클클릭", wcslen(L"마우스 왼쪽 버튼 더클클릭"));
        hMyBr = CreateSolidBrush(RGB(255, 0, 0));
        holdBr = (HBRUSH)SelectObject(hdc,(HBRUSH)hMyBr);
        Rectangle(hdc, 130, 150, 180, 250);
        SelectObject(hdc, holdBr);

        break;
    case MouseMSG::RDBLK:
        TextOut(hdc, 10, 10, L"마우스 오른쪽 버튼 눌러짐", wcslen(L"마우스 오른쪽 버튼 눌러짐"));
        hMyBr = CreateSolidBrush(RGB(0, 0, 255));
        holdBr = (HBRUSH)SelectObject(hdc, (HBRUSH)hMyBr);
        Rectangle(hdc, 220, 150, 270, 250);
        SelectObject(hdc, holdBr);
        break;
    case MouseMSG::MDBLK:
        TextOut(hdc, 10, 10, L"마우스 중간 버튼 더클클릭", wcslen(L"마우스  중간 버튼 더클클릭"));
        hMyBr = CreateSolidBrush(RGB(0, 255, 0));
        holdBr = (HBRUSH)SelectObject(hdc, (HBRUSH)hMyBr);
        Ellipse(hdc, 180, 160, 220, 240);
        SelectObject(hdc, holdBr);
        break;
    case MouseMSG::LBD:
        TextOut(hdc, 10, 10, L"마우스 왼쪽 버튼 눌러짐", wcslen(L"마우스 왼쪽 버튼 눌러짐"));
        hMyBr = CreateSolidBrush(RGB(255, 0, 0));
        holdBr = (HBRUSH)SelectObject(hdc, (HBRUSH)hMyBr);
        Rectangle(hdc, 130, 150, 180, 250);
        SelectObject(hdc, holdBr);
        break;
    case MouseMSG::LBU:
        TextOut(hdc, 10, 10, L"마우스 왼쪽 버튼 떼짐", wcslen(L"마우스 왼쪽 버튼 떼짐"));
        hMyBr = CreateSolidBrush(RGB(255, 0, 0));
        holdBr = (HBRUSH)SelectObject(hdc, (HBRUSH)hMyBr);
        Rectangle(hdc, 130, 150, 180, 250);
        SelectObject(hdc, holdBr);
        break;
    case MouseMSG::RBD:
        TextOut(hdc, 10, 10, L"마우스 오른쪽 버튼 눌러짐", wcslen(L"마우스 오른쪽 버튼 눌러짐"));
        hMyBr = CreateSolidBrush(RGB(255, 0, 0));
        Rectangle(hdc, 220, 150, 270, 250);
        SelectObject(hdc, holdBr);
        break;
    case MouseMSG::RBU:
        TextOut(hdc, 10, 10, L"마우스 오른쪽 버튼 떼짐", wcslen(L"마우스 오른쪽 버튼 떼짐"));
        hMyBr = CreateSolidBrush(RGB(255, 0, 0));
        holdBr = (HBRUSH)SelectObject(hdc, (HBRUSH)hMyBr);
        Rectangle(hdc, 130, 150, 180, 250);
        SelectObject(hdc, holdBr);
        break;
    case MouseMSG::MBD:
        TextOut(hdc, 10, 10, L"마우스 중간 버튼 눌러짐", wcslen(L"마우스 중간 버튼 눌러짐"));
        hMyBr = CreateSolidBrush(RGB(255, 0, 0));
        holdBr = (HBRUSH)SelectObject(hdc, (HBRUSH)hMyBr);
        Rectangle(hdc, 130, 150, 180, 250);
        SelectObject(hdc, holdBr);
        break;
    case MouseMSG::MBU:
        TextOut(hdc, 10, 10, L"마우스 중간 버튼 떼짐", wcslen(L"마우스 중간 버튼 떼짐"));
        hMyBr = CreateSolidBrush(RGB(255, 0, 0));
        holdBr = (HBRUSH)SelectObject(hdc, (HBRUSH)hMyBr);
        Rectangle(hdc, 130, 150, 180, 250);
        SelectObject(hdc, holdBr);
        break;
    default:
        TextOut(hdc, 10, 10, L"마우스 버튼 눌러지지 않음", wcslen(L"마마우스 버튼 눌러지지 않음"));
        break;
    }
    EndPaint(hWnd, &ps);

    return 0;
}

int Destroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    PostQuitMessage(0);

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_MOUSEWHEEL: return OnMouseWhell(hWnd, wParam, lParam);

    case WM_LBUTTONDBLCLK:
        return OnMouseLBTNDBLCK(hWnd, wParam, lParam);

    case WM_RBUTTONDBLCLK:
        return OnMouseRBTNDBLCK(hWnd, wParam, lParam);

    case WM_MBUTTONDBLCLK:
        return OnMouseMBTNDBLCK(hWnd, wParam, lParam);

    case WM_LBUTTONDOWN: //마우스 윈쩍버튼 눌림
        return OnMouseLBUTTONDOWN(hWnd, wParam, lParam);

    case WM_LBUTTONUP: //마우스 왼쪽버튼 떼짐
        return OnMouseLBUTTONUP(hWnd, wParam, lParam);

    case WM_RBUTTONDOWN: //마우스 오른쪽버튼 눌림
        return OnMouseRBUTTONDOMN(hWnd, wParam, lParam);

    case WM_RBUTTONUP: //마우스 오른쪽버튼 떄짐
        return OnMouseRBUTTONUP(hWnd, wParam, lParam);

    case WM_MBUTTONDOWN: //마우스 중간쪽버튼 눌림
        return OnMouseMBUTTONDOWN(hWnd, wParam, lParam);

    case WM_MBUTTONUP: //마우스 중간쪽버튼 떄짐
        return OnMouseMBUTTONUP(hWnd, wParam, lParam);

    case WM_MOUSEMOVE://마우스 이동
    {
        TCHAR strTemp[128];
        int x = LOWORD(lParam);
        int y = LOWORD(lParam);
        wsprintf(strTemp, L"마우스 좌표[%04d,%04d", x, y);
        SetWindowText(hWnd, strTemp);
    }

    break;
    case WM_COMMAND: return OnCommand(hWnd, wParam, lParam);

        break;
    case WM_PAINT: return OnPaint(hWnd, wParam, lParam);
    case WM_DESTROY:

        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
