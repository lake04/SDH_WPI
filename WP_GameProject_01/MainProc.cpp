#include "pch.h"
#include "MainProc.h"

extern HINSTANCE hInst;
extern BOOL bIsLoopExit;
extern BOOL bIsActive;
extern int nFPS;
extern int nCount;
extern HDC gHDC;
extern HWND ghWnd;

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    ghWnd = hWnd;
    Start();
    SetTimer(hWnd, 0, 1000, NULL);
    gHDC = GetDC(hWnd);
    bIsActive = TRUE;
    return 0;
}

int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    Release();
    bIsActive = FALSE;
    bIsLoopExit = FALSE;
    ReleaseDC(hWnd, gHDC);
    KillTimer(hWnd, 0);
    PostQuitMessage(0);
    return 0;
}

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

//int OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam)
//{
//    PAINTSTRUCT ps;
//    HDC hdc = BeginPaint(hWnd, &ps);
//    // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
//    EndPaint(hWnd, &ps);
//    return 0;
//}

extern DINO* Dino;


int OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    if (wParam == 0)
    {
        nFPS = nCount;
        nCount = 0;
    }

    if (wParam == 100)
    {
        if (getJump(Dino) == true)
        {
            setJump(Dino, false);
            KillTimer(hWnd, 100);
        }
        
        
    }
    

    return 0;
}

int OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    if (getJump(Dino) == false)
    {
        setJump(Dino, true);
        SetTimer(hWnd,100, 300, NULL);
    }
  
    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE: return OnCreate(hWnd, wParam, lParam);
    case WM_COMMAND:return OnCommand(hWnd, wParam, lParam);
    case WM_TIMER:  return OnTimer(hWnd, wParam, lParam);
    case WM_KEYDOWN: return OnKeyDown(hWnd, wParam, lParam);
//    case WM_PAINT:  return OnPaint(hWnd, wParam, lParam);
    case WM_DESTROY:return OnDestroy(hWnd, wParam, lParam);
    default:        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}