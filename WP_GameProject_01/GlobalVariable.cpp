#include "pch.h"
#include "GlobalVariable.h"


//���� ������ �ý��� ��� ��������
HINSTANCE hInst = NULL;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING] = _T("");                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING] = _T("");            // �⺻ â Ŭ���� �̸��Դϴ�.

//�������ν��� ��������
BOOL bIsLoopExit = TRUE;
BOOL bIsActive = FALSE;
int nFPS = 0;
int nCount = 0;
HDC gHDC = NULL;
HWND ghWnd = NULL;

//GamgeManager ��������
HDC ScreenDC = NULL; //ȭ��DC //����DC
HDC MemoryDC = NULL; //�޸𸮿��� �̹����� ������ DC
HBITMAP hBitmap = NULL; //�ش�DC�� �̹��� ��ü