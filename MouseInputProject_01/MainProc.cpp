#include "pch.h"
#include "MainProc.h"

extern HINSTANCE hInst;

enum MouseMSG{NONE,LBD,LBU,RBD,RBU,MBD,MBU, LDBLK, RDBLK, MDBLK};
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static MouseMSG mousetState = NONE;
    static TCHAR strWheelValue[128] = L"";

    switch (message)
    {
    case WM_MOUSEWHEEL:
    {
        int zDelta = GET_WHEEL_DELTA_WPARAM(wParam);
        wsprintf(strWheelValue, L"휠 회전값 : %3d", zDelta/WHEEL_DELTA);
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    }
        
    case WM_LBUTTONDBLCLK:
        mousetState = LDBLK;
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_RBUTTONDBLCLK:
        mousetState = RDBLK;
        InvalidateRect(hWnd, NULL, TRUE);
     break;
    case WM_MBUTTONDBLCLK:
        mousetState = MDBLK;
        InvalidateRect(hWnd, NULL, TRUE);
        break;

    case WM_LBUTTONDOWN: //마우스 윈쩍버튼 눌림
        mousetState = MouseMSG::LBD;
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_LBUTTONUP: //마우스 왼쪽버튼 떼짐
        mousetState = MouseMSG::LBU;
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_RBUTTONDOWN: //마우스 오른쪽버튼 눌림
        mousetState = MouseMSG::RBD;
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_RBUTTONUP: //마우스 오른쪽버튼 떄짐
        mousetState = MouseMSG::RBU;
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_MBUTTONDOWN: //마우스 중간쪽버튼 눌림
        mousetState = MouseMSG::MBD;
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_MBUTTONUP: //마우스 중간쪽버튼 떄짐
        mousetState = MouseMSG::MBU;
        InvalidateRect(hWnd, NULL, TRUE);

        break;
    case WM_MOUSEMOVE://마우스 이동
    {
        TCHAR strTemp[128];
        int x = LOWORD(lParam);
        int y = LOWORD(lParam);
        wsprintf(strTemp, L"마우스 좌표[%04d,%04d", x, y);
        SetWindowText(hWnd, strTemp);
    }
        break;
    case WM_COMMAND:
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
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        TextOut(hdc, 10, 30, strWheelValue, wcslen(strWheelValue));
        switch (mousetState)
        {
        case MouseMSG::LDBLK:
            TextOut(hdc, 10, 10, L"마우스 왼쪽 버튼 더클클릭", wcslen(L"마우스 왼쪽 버튼 더클클릭"));
            break;
        case MouseMSG::RDBLK:
            TextOut(hdc, 10, 10, L"마우스 오른쪽 버튼 눌러짐", wcslen(L"마우스 오른쪽 버튼 눌러짐"));
            break;
        case MouseMSG::MDBLK:
            TextOut(hdc, 10, 10, L"마우스 중간 버튼 더클클릭", wcslen(L"마우스  중간 버튼 더클클릭"));
            break;
        case MouseMSG::LBD:
            TextOut(hdc, 10, 10, L"마우스 왼쪽 버튼 눌러짐", wcslen(L"마우스 왼쪽 버튼 눌러짐"));
            break;
        case MouseMSG::LBU:
            TextOut(hdc, 10, 10, L"마우스 왼쪽 버튼 떼짐", wcslen(L"마우스 왼쪽 버튼 떼짐"));
            break;
        case MouseMSG::RBD:
            TextOut(hdc, 10, 10, L"마우스 오른쪽 버튼 눌러짐", wcslen(L"마우스 오른쪽 버튼 눌러짐"));
            break;
        case MouseMSG::RBU:
            TextOut(hdc, 10, 10, L"마우스 오른쪽 버튼 떼짐", wcslen(L"마우스 오른쪽 버튼 떼짐"));
            break;
        case MouseMSG::MBD:
            TextOut(hdc, 10, 10, L"마우스 중간 버튼 눌러짐", wcslen(L"마우스 중간 버튼 눌러짐"));
            break;
        case MouseMSG::MBU:
            TextOut(hdc, 10, 10, L"마우스 중간 버튼 떼짐", wcslen(L"마우스 중간 버튼 떼짐"));
            break;
        default:
            TextOut(hdc, 10, 10, L"마우스 버튼 눌러지지 않음", wcslen(L"마마우스 버튼 눌러지지 않음"));
            break;
        }
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}