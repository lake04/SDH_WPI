#include "pch.h"
#include "gdiUtil.h"

void gdiRotLineCW(HDC hdc, int x, int y, int length, float theta)
{
	int NeddleX = cos(theta) * length - sin(theta) * length;
	int NeddleY = cos(theta) * length + sin(theta) * length;
	gdiLine(hdc, x, y, NeddleX + x, NeddleY + y);
}
void gdiLine(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);

}

void CBS_Num1(HDC hdc, int cx, int cy, int length)
{
	for (int i = 0, j = 0; i < 360; i+=30, j++)
	{
		float fTheta = RAD((float)((i - 135.f))); // -12.5로 보정
		int x = (int)((cos(fTheta) * length) - (sin(fTheta) * length));
		int y = (int)((sin(fTheta) * length) + (cos(fTheta) * length));
		TCHAR strTemp[3] = L"";
		wsprintf(strTemp, L"%2d", j == 0 ? 12 : j);
		TextOut(hdc, cx + x - 10, cy + y -10, strTemp, lstrlen(strTemp));
	}
}

void CBS_Num2(HDC hdc, int cx, int cy, int length)
{
	for (int i = 0, j = 0; i < 360; i += 90, j+=3)
	{
		float fTheta = RAD((float)((i - 135.f))); 
		int x = (int)((cos(fTheta) * length) - (sin(fTheta) * length));
		int y = (int)((sin(fTheta) * length) + (cos(fTheta) * length));
		TCHAR strTemp[3] = L"";
		wsprintf(strTemp, L"%2d", j == 0 ? 12 : j);
		TextOut(hdc, cx + x - 10, cy + y - 10, strTemp, lstrlen(strTemp));
	}
}

void CBS_Num3(HDC hdc, int cx, int cy, int length)
{
	for (int i = 0, j = 0; i < 360; i += 6, j ++)
	{
		float fTheta = RAD((float)((i - 135.f)));
		int x = (int)((cos(fTheta) * length) - (sin(fTheta) * length));
		int y = (int)((sin(fTheta) * length) + (cos(fTheta) * length));
		TCHAR strTemp[3] = L"";
		wsprintf(strTemp, L"%2d",j);
		TextOut(hdc, cx + x - 10, cy + y - 10, strTemp, lstrlen(strTemp));
	}
}

void CBS_Needle1(HDC hdc, int cx, int cy, int length)
{
	for (int i = 0; i < 360; i += 30)
	{
		float fTheta = RAD((float)((i - 135.f)));
		int x1 = (int)((cos(fTheta) * length) - (sin(fTheta) * length));
		int y1 = (int)((sin(fTheta) * length) + (cos(fTheta) * length));
		int x2 = (int)((cos(fTheta) * length - 10) - (sin(fTheta) * length - 10));
		int y2 = (int)((sin(fTheta) * length - 10) + (cos(fTheta) * length - 10));

		gdiLine(hdc, cx + x1, cy + y1, cx + x2, cy + y2);
	}
}

void CBS_Needle2(HDC hdc, int cx, int cy, int length)
{
	for (int i = 0; i < 360; i += 6)
	{
		float fTheta = RAD((float)((i - 135.f)));
		int x1 = (int)((cos(fTheta) * length) - (sin(fTheta) * length));
		int y1 = (int)((sin(fTheta) * length) + (cos(fTheta) * length));
		int x2 = (int)((cos(fTheta) * length - 10) - (sin(fTheta) * length - 10));
		int y2 = (int)((sin(fTheta) * length - 10) + (cos(fTheta) * length - 10));

		gdiLine(hdc, cx + x1, cy + y1, cx + x2, cy + y2);
	}
}

