#include "pch.h"
#include "MainProc.h"

extern HINSTANCE hInst;

SYSTEMTIME gST;
MYCLOCK* g_pClock;

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    SetTimer(hWnd, 0, 1000, NULL);

    g_pClock = StartMyClock(300, 20, 500, 500); //g_pClock 시계 객체생성
    return 0;
}

int OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    GetLocalTime(&gST);
    SetTime(g_pClock, gST); //시간 설정

    InvalidateRect(hWnd, NULL, true);
    
    return 0;
}

int OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    int wmId = LOWORD(wParam);
    // 메뉴 선택을 구문 분석합니다:
    static int clockStyle = NULL;
    static int hourPenThick = 5;

    static COLORREF myColor = RGB(0,0,0) ; 
    CHOOSECOLOR cc; //컬러다이얼로그 구조체
    static COLORREF crtTemp[16]; //커스텀 섹 저장소
    ZeroMemory(&cc, sizeof(COLORREF)); //cc 초기화
    cc.lStructSize = sizeof(CHOOSECOLOR); //cc크기지정
    cc.hwndOwner = hWnd;//윈도우핸들
    cc.lpCustColors = crtTemp; //커스텀컬러저장소 연결
    cc.Flags = CC_FULLOPEN; //기본 플래그 설정
        
    switch (wmId)
    {
    case IDM_RECT:
        clockStyle += CBS_RECT;
        break;
    case IDM_CIRCLE:
        clockStyle += CBS_CIRCLE;
        break;
    case IDM_NUM1:
        clockStyle += CBS_NUM1;
        break;
    case IDM_NUM2:
        clockStyle += CBS_NUM2;
        break;
    case IDM_NUM3:
        clockStyle += CBS_NUM3;
        break;

    case IDM_HOURTHICK:
        if ((hourPenThick +=5) >= 30) hourPenThick = 10;
        g_pClock->pHour->color = (HPEN)CreatePen(PS_SOLID, hourPenThick, myColor);
        break;
    case IDM_HOURCOLOR:
        ChooseColor(&cc); //다이얼로그창 실행
        g_pClock->pHour->color = (HPEN)CreatePen(PS_SOLID, hourPenThick, cc.rgbResult);
        myColor = cc.rgbResult;
            break;
    case IDM_ABOUT:
        DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
        break;
    case IDM_EXIT:
        DestroyWindow(hWnd);
        break;
    default:
        return DefWindowProc(hWnd, WM_COMMAND, wParam, lParam);
    }
    SetBK(g_pClock, clockStyle);

    return 0;
}

int OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

    SetHDC(g_pClock, hdc);
    Update(g_pClock);

    // 원 둘레의 좌표를 추출하는 공식
    // //원래공식
    //  x =  cos() * len + sin() * len
    //  y = -sin() * len + cos() * len
    // //변경 시계방향 CW
    //  x = cos() * len - sin() * len
    //  y = cos() * len + sin() * len

    return 0;
}

int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    Release(g_pClock);
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
