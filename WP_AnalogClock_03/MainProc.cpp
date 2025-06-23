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

int OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);

    int centerX =400;
    int centerY = 300;
    int radius = 230;

    // 시계 배경 원
    HBRUSH hBrush = CreateSolidBrush(RGB(60, 0, 0));
    HPEN hPen = CreatePen(PS_SOLID, 8, RGB(255, 50, 50));
    SelectObject(hdc, hPen);
    SelectObject(hdc, hBrush);
    Ellipse(hdc, centerX - radius, centerY - radius, centerX + radius, centerY + radius);
    Ellipse(hdc, centerX - 200, centerY - 200, centerX + 200, centerY + 200);
    DeleteObject(hPen);
    DeleteObject(hBrush);

    // 내부 원 장식
    HPEN yellowPen = CreatePen(PS_SOLID, 8, RGB(255, 240, 0));
    SelectObject(hdc, yellowPen);
    Ellipse(hdc, centerX - 40, centerY - 40, centerX + 40, centerY + 40);
    Ellipse(hdc, centerX - 15, centerY - 15, centerX + 15, centerY + 15);
    DeleteObject(yellowPen);

    // 시침 그리기
    float hourTheta = RAD((float)((gST.wHour % 12 + gST.wMinute / 60.0f - 3) * 30));
    int hourX = cos(hourTheta) * 100;
    int hourY = sin(hourTheta) * 100;
    MoveToEx(hdc, centerX, centerY, NULL);
    LineTo(hdc, centerX + hourX, centerY + hourY);

    // 분침 그리기
    float minTheta = RAD((float)((gST.wMinute - 15) * 6));
    int minX = cos(minTheta) * 130;
    int minY = sin(minTheta) * 130;
    MoveToEx(hdc, centerX, centerY, NULL);
    LineTo(hdc, centerX + minX, centerY + minY);

    // 불꽃 효과
    for (int i = 0; i < 10; ++i) {
        int flameX = centerX + (rand() % 100 - 50);
        int flameY = centerY - radius + (rand() % 30 + 10);
        HBRUSH flame = CreateSolidBrush(RGB(255, rand() % 100 + 150, 0));
        SelectObject(hdc, flame);
        Ellipse(hdc, flameX, flameY, flameX + 8, flameY + 15);
        DeleteObject(flame);
    }

    // 숫자 출력 설정
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, RGB(255, 250, 250));

    // 숫자 1~12 출력
    for (int i = 1; i <= 12; ++i) {
        float angle = RAD((float)(i * 30 - 90));
        int tx = centerX + cos(angle) * (radius - 30);
        int ty = centerY + sin(angle) * (radius - 30);

        // 숫자 안쪽 작은 점 그리기
        HBRUSH screwBrush = CreateSolidBrush(RGB(100, 0, 0));
        HPEN screwPen = CreatePen(PS_SOLID, 1, RGB(200, 100, 100));
        SelectObject(hdc, screwBrush);
        SelectObject(hdc, screwPen);
        Ellipse(hdc, tx - 12, ty - 12, tx + 12, ty + 12);
        DeleteObject(screwBrush);
        DeleteObject(screwPen);

        // 숫자 문자열 출력
        WCHAR numStr[3];
        swprintf(numStr, 3, L"%d", i);
        TextOut(hdc, tx - 6, ty - 8, numStr, wcslen(numStr));
    }

    EndPaint(hWnd, &ps);
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
