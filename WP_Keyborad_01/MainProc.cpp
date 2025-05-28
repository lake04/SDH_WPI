﻿#include "pch.h"
#include "MainProc.h"

extern HINSTANCE hInst;

static int length =0;
TCHAR strBuffer[128];
POINT ptPos = { 0,0 };

int OnCreate(HWND hWnd, WPARAM wParam,LPARAM lParam)
{
    return 0;
}

int OnChar(HWND hWnd, WPARAM wParam, LPARAM lParam)
{

    strBuffer[length] = (TCHAR)wParam;
    strBuffer[length + 1] = NULL;
    //length++;
    InvalidateRect(hWnd, NULL, TRUE);

    return 0;
}
int OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    switch (wParam)
    {
    case 'w': 
    case 'W':ptPos.y -= 5; break;

    case 's':
    case 'S':ptPos.y += 5; break;

    case 'a':
    case 'A':ptPos.x -= 5; break;

    case 'd':
    case 'D':ptPos.x += 5; break;
   
    case VK_UP:
        ptPos.y -= 5;
        break;
    case VK_DOWN:
        ptPos.y += 5;
        break;
    case VK_LEFT:
        ptPos.x -= 5;
        break;
    case VK_RIGHT:
        ptPos.x += 5;
        break;
    }
    InvalidateRect(hWnd, NULL, TRUE);
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
int OnPaint(HWND hWnd,WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
    TextOut(hdc, 100 + ptPos.x, 100 + ptPos.y, strBuffer, wcslen(strBuffer));
    EndPaint(hWnd, &ps);
    return 0;
}

int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    PostQuitMessage(0);
    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:  return OnCreate(hWnd, wParam, lParam);
    case WM_CHAR:    return OnChar(hWnd, wParam, lParam);
    case WM_KEYDOWN: return OnKeyDown(hWnd, wParam, lParam);
    case WM_COMMAND: return OnCommand(hWnd, wParam, lParam);
    case WM_PAINT:   return  OnPaint(hWnd, wParam, lParam);
    case WM_DESTROY:OnDestroy(hWnd,wParam,lParam);
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

