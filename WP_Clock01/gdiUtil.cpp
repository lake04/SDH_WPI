#include "pch.h"
#include "gdiUtil.h"

//=============================================
// Desc : windois GDI ���� �׸��� �Լ�
// Parameter : HDC, ������(x1,y1),����(x2,y2)
// Author :JungHwan_Kim (eamill :sdh240204@sdh.hs.kr)
// Date : 2025-04-14
int GdiLine(HDC hdc, int x1,int y1,int x2,int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2 , y2);

	return 0;
}

//=============================================
// Desc : windois GDI ���� �׸��� �Լ�
// Parameter : HDC, ��ǥ(mx,my),ũ��(scale)
// Author :JungHwan_Kim (eamill :sdh240204@sdh.hs.kr)
// Date : 2025-04-14

void gdiStar(HDC hdc, int mx, int my,int scale)
{
	MoveToEx(hdc, mx + 0   * scale,    my + -10 * scale, NULL);
	LineTo(hdc,   mx + 6   * scale,    my + 8	* scale);
	LineTo(hdc,   mx + -10 * scale,	   my + -3  * scale);
	LineTo(hdc,   mx + 10  * scale,    my + -3  * scale);
	LineTo(hdc,   mx + -6  * scale,    my + 8	* scale);
	LineTo(hdc,   mx + 0   * scale,    my + -10 * scale);
}

