#pragma once

enum MouseMSG { NONE = 0, LBD, LBU, RBD, RBU, MBD, MBU, LDBLK, RDBLK, MDBLK, MSG_COUNT };
enum MouseBtn { LEFT = 0, RIGHT = 1, MIDDLE = 2, NORMAL = 0, DOWN = 1 };

typedef struct ___MOUSE_BUTTON
{
    RECT rect;
    COLORREF normalColor, downColor;
    BOOL isDown;
}MOUSEBTN;

typedef struct ___MOUSE_OBJECT MOUSE_OBJ; // 미리 선언

typedef int (*MouseEventHandler)(MOUSE_OBJ* mouse, HWND, WPARAM, LPARAM);

typedef struct ___MOUSE_OBJECT
{
    // 입력 상태
    int x, y;
    MouseMSG state;
    int wheelDelta; //휠
    TCHAR strWheel[32]; //휠정보

    // 렌더링
    int w, h;
    HPEN hPen;
    HBRUSH hBodyBrush, hHighlight, hWheelBrush;
    HBRUSH hButtonBrushes[3][2]; // [0:left, 1:right, 2:middle][0:normal,1:down]
    MOUSEBTN buttons[3]; // 0:left 1:right 2:middle

    // 휠 정보
    int wheel_cx, wheel_cy, wheel_r; //휠
    int strWhell[32]; //휠 정보

    MouseEventHandler handlers[MSG_COUNT];

    void (*Draw)(MOUSE_OBJ*, HDC);
    void (*Update)(MOUSE_OBJ*, MouseMSG, LPARAM);
    void (*SetWheel)(MOUSE_OBJ*, WPARAM);
    void (*Release)(MOUSE_OBJ*);

}MOUSE_OBJ;

// 메서드
MOUSE_OBJ* StartMouseObject(int x, int y, int w, int h); //마우스 객체 생성
void Draw(MOUSE_OBJ* mouse, HDC hdc); //마우스 그리기
void Update(MOUSE_OBJ* mouse, MouseMSG state, LPARAM lParam); //마우스 상태 업데이트
void SetWheel(MOUSE_OBJ* mouse, WPARAM wParam); //마우스 휠 전보
void Release(MOUSE_OBJ* mouse); //마우스 객체 해제

inline int MouseOnNone(MOUSE_OBJ* mouse, HWND hWnd, WPARAM wParam, LPARAM lParam) { return 0; }
inline int MouseOnLBD(MOUSE_OBJ* mouse, HWND hWnd, WPARAM wParam, LPARAM lParam) { mouse->Update(mouse, MouseMSG::LBD, lParam); InvalidateRect(hWnd, NULL, FALSE); return 0; }
inline int MouseOnLBU(MOUSE_OBJ* mouse, HWND hWnd, WPARAM wParam, LPARAM lParam) { mouse->Update(mouse, MouseMSG::LBU, lParam); InvalidateRect(hWnd, NULL, FALSE); return 0; }
inline int MouseOnRBD(MOUSE_OBJ* mouse, HWND hWnd, WPARAM wParam, LPARAM lParam) { mouse->Update(mouse, MouseMSG::RBD, lParam); InvalidateRect(hWnd, NULL, FALSE); return 0; }
inline int MouseOnRBU(MOUSE_OBJ* mouse, HWND hWnd, WPARAM wParam, LPARAM lParam) { mouse->Update(mouse, MouseMSG::RBU, lParam); InvalidateRect(hWnd, NULL, FALSE); return 0; }
inline int MouseOnMBD(MOUSE_OBJ* mouse, HWND hWnd, WPARAM wParam, LPARAM lParam) { mouse->Update(mouse, MouseMSG::MBD, lParam); InvalidateRect(hWnd, NULL, FALSE); return 0; }
inline int MouseOnMBU(MOUSE_OBJ* mouse, HWND hWnd, WPARAM wParam, LPARAM lParam) { mouse->Update(mouse, MouseMSG::MBU, lParam); InvalidateRect(hWnd, NULL, FALSE); return 0; }
inline int MouseOnLDBLK(MOUSE_OBJ* mouse, HWND hWnd, WPARAM wParam, LPARAM lParam) { mouse->Update(mouse, MouseMSG::LDBLK, lParam); InvalidateRect(hWnd, NULL, FALSE); return 0; }
inline int MouseOnRDBLK(MOUSE_OBJ* mouse, HWND hWnd, WPARAM wParam, LPARAM lParam) { mouse->Update(mouse, MouseMSG::RDBLK, lParam); InvalidateRect(hWnd, NULL, FALSE); return 0; }
inline int MouseOnMDBLK(MOUSE_OBJ* mouse, HWND hWnd, WPARAM wParam, LPARAM lParam) { mouse->Update(mouse, MouseMSG::MDBLK, lParam); InvalidateRect(hWnd, NULL, FALSE); return 0; }

