#include "pch.h"
#include "Dino.h"

extern HINSTANCE hInst;
extern HWND ghWnd;

DINO* StartDino(HDC hdc, int resource)
{
	DINO* Temp;
	Temp = (DINO*)malloc(sizeof(DINO));

	Temp->hImgDC = CreateCompatibleDC(hdc);
	Temp->hImgBM = LoadBitmap(hInst, MAKEINTRESOURCE(resource));
	SelectObject(Temp->hImgDC, Temp->hImgBM);

	//보여지는 이미지 크기
	Temp->x = 20; Temp->y = 0;
	Temp->w = 49; Temp->h = 50;

	//원본 이미지 크기
	Temp->sx = 0; Temp->sy = 0;
	Temp->ex = 192; Temp->ey = 192;

	setJump(Temp, false);

	return Temp;
}

void Update(DINO* Obj)
{
	if (getJump(Obj) == true)
	{
		Obj->y = 20;
	}
	else
	{
		Obj->y = 100;
	}
}
void Render(HDC hdc, DINO* Obj)
{


	//BitBlt(hdc, Obj->x, Obj->y, Obj->w, Obj->h, Obj->hImgDC, Obj->sx, Obj->sy, SRCCOPY);
	TransparentBlt(hdc, Obj->x, Obj->y, Obj->w, Obj->h,
		Obj->hImgDC, Obj->sx, Obj->sy, Obj->ex, Obj->ey, RGB(255, 255, 255));

}
void Release(DINO* Obj)
{
	DeleteObject(Obj->hImgBM);
	ReleaseDC(ghWnd, Obj->hImgDC);
	if (Obj != NULL) free(Obj);

}
