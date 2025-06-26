#include "pch.h"
#include "Cloud.h"

extern HINSTANCE hInst;
extern HWND ghWnd;

CLOUD* StartCloud(HDC hdc, int resource)
{
	CLOUD* Temp;
	Temp = (CLOUD*)malloc(sizeof(CLOUD));

	Temp->hImgDC = CreateCompatibleDC(hdc);
	Temp->hImgBM = LoadBitmap(hInst, MAKEINTRESOURCE(resource));
	SelectObject(Temp->hImgDC, Temp->hImgBM);

	//보여지는 이미지 크기
	Temp->x = 400;	Temp->y = 220;
	Temp->w = 39;	Temp->h = 76;

	//원본 이미지 크기
	Temp->sx = 0;	Temp->sy = 0;
	Temp->ex = 39; Temp->ey =76;

	setSpeedX(Temp, -3);

	return Temp;
}

void Update(CLOUD* Obj)
{
	Obj->x += Obj->speedX;
	if (Obj->x < (0 - Obj->w)) setX(Obj, rand() % 5 * 300 + 800);
}

void Render(HDC hdc, CLOUD* Obj)
{
	//BitBlt(hdc, Obj->x, Obj->y, Obj->w, Obj->h, Obj->hImgDC, Obj->sx, Obj->sy, SRCCOPY);
	TransparentBlt(hdc, Obj->x, Obj->y, Obj->w, Obj->h,
		Obj->hImgDC, Obj->sx, Obj->sy, Obj->ex, Obj->ey, RGB(255, 255, 255));
}

void Release(CLOUD* Obj)
{
	DeleteObject(Obj->hImgBM);
	ReleaseDC(ghWnd, Obj->hImgDC);
	if (Obj != NULL)	free(Obj);
}