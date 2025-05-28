#include "pch.h"
#include "MainProc.h"

extern HINSTANCE hInst;

SYSTEMTIME gST;
HFONT ghFont;

HPEN hOldPen;
HPEN hRedPen;
HPEN hGreenPen;
HPEN hBluePen;
HPEN hYellowPen;
HPEN hBlackPen;
HPEN hWhitePen;

HBRUSH hOldBrush;
HBRUSH hRedBrush;
HBRUSH hGreenBrush;
HBRUSH hBlueBrush;
HBRUSH hYellowBrush;
HBRUSH hBlackBrush;
HBRUSH hWhiteBrush;


#define PI 3.141592f
#define RAD(x) PI/180.0f*(x)

//WM_CREATE 실행 함수 //윈도우가 만들어질 때 한 번만 호출
int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    SetTimer(hWnd, 0, 1000, NULL); //시간 설정 ID(0번), 1000(1초)

    hRedPen =    CreatePen(PS_SOLID,1,RGB(255,0,0));
    hGreenPen =  CreatePen(PS_SOLID,1,RGB(0, 255,0));
    hBluePen =   CreatePen(PS_SOLID,1,RGB(0,0, 255));
    hYellowPen = CreatePen(PS_SOLID,1,RGB(255, 255,0));
    hBlackPen =  CreatePen(PS_SOLID,1,RGB(0, 0, 0));
    hWhitePen =  CreatePen(PS_SOLID,1,RGB(255, 255, 255));

    hRedBrush      = CreateSolidBrush(RGB(255,0,0));
    hGreenBrush    = CreateSolidBrush(RGB(0,255,0));
    hBlueBrush      = CreateSolidBrush(RGB(0,0,255));
    hYellowBrush   = CreateSolidBrush(RGB(255,255,0));
    hBlackBrush    = CreateSolidBrush(RGB(0,0,0));
    hWhiteBrush    = CreateSolidBrush(RGB(255, 255, 255));

    return 0;
}

//WM_TIMER 실행 함수 //윈도우 종료 전까지 정해진 시간마다 반복 호출 
int OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    GetLocalTime(&gST);//SYSTEMTIME구조체 변수 값 저장하기

    TCHAR strTime[128];
    wsprintf(strTime, L"%02d:%d02:%02d", gST.wHour, gST.wMinute, gST.wSecond);
    SetWindowText(hWnd, strTime);
    InvalidateRect(hWnd, NULL, TRUE); //무효화선언하여 WM_PAINT호출
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

int OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    static bool bIsBlink = true;

    // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
    //Rectangle(hdc, 0, 0, 1000, 500);
    //gdiLine(hdc, 500, 0, 500, 500); //x자표가 같음(수직선)
    //gdiLine(hdc, 0, 250, 1000, 250); //y좌표가 같음(수평선)

    hOldPen = (HPEN)SelectObject(hdc, hRedPen);
    hOldBrush = (HBRUSH)SelectObject(hdc, hGreenBrush);

    Rectangle(hdc, 100, 100, 400, 400);
    SelectObject(hdc, hYellowBrush);
    SelectObject(hdc, hBlackPen);
    Ellipse(hdc, 100, 100, 400, 400);

    gdiLine(hdc, 100, 100, 400, 400);
    SelectObject(hdc, hBlueBrush);
    gdiLine(hdc, 100, 400, 400, 100);

    SelectObject(hdc, hOldBrush);
    SelectObject(hdc, hOldPen);

    //원 둘레의 좌표를 추출하는 공식
    // //원래공식
    // x =  cos() * len + sin() * len
    // y = -sin() * len + cos() * len
    // //변경 시계방향
    // x = cos() * len - sin() * len
    // y = cos() * len + sin() * len

    //시계
    {
       // int centerX = 500; //초바늘 시작점
       // int centerY = 250; //초바늘 시작점

       // Ellipse(hdc, -230 + centerX, -230 + centerY, 230 + centerX, 230 + centerY);
       //float Sectheta = RAD((float)((gST.wSecond - 22.5) * 6.0f));
       // gdiRotLineCW(hdc, 500, 250, 160, Sectheta);

       // float Mintheta = RAD((float)((gST.wMinute - 22.5) * 6.0f));
       // gdiRotLineCW(hdc, 500, 250, 160, Mintheta);

       // float Hourtheta = RAD((float)((gST.wHour - 4.5) * 30.0f));
       // gdiRotLineCW(hdc, 500, 250, 100, Hourtheta);
    } 
    
   
    EndPaint(hWnd, &ps);
    return 0;
}

int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    DeleteObject(ghFont); //생성된 폰트 삭제

    DeleteObject(hWhitePen);
    DeleteObject(hRedPen);
    DeleteObject(hGreenPen);
    DeleteObject(hBluePen);
    DeleteObject(hYellowPen);
    DeleteObject(hBlackPen);

    DeleteObject(hWhiteBrush);
    DeleteObject(hRedBrush);
    DeleteObject(hGreenBrush);
    DeleteObject(hBlueBrush);
    DeleteObject(hYellowBrush);
    DeleteObject(hBlackBrush);


    KillTimer(hWnd, 0); //생성된 시계 삭제
    PostQuitMessage(0);
    return 0;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:     return OnCreate(hWnd, wParam, lParam);
    case WM_TIMER:      return OnTimer(hWnd, wParam, lParam);
    case WM_COMMAND:    return OnCommand(hWnd, wParam, lParam);
    case WM_PAINT:      return OnPaint(hWnd, wParam, lParam);
    case WM_DESTROY:    return OnDestroy(hWnd, wParam, lParam);
    default:            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
