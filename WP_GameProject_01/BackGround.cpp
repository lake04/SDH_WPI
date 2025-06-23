#include "pch.h"
#include "BackGround.h"

extern HINSTANCE hInst;
extern HWND ghWnd;

BACKGROUND* StartBackground(HDC hdc, int resource)
{
	BACKGROUND* Temp;
	Temp = (BACKGROUND*)malloc(sizeof(BACKGROUND));

	Temp->hImgDC = CreateCompatibleDC(hdc);
	Temp->hImgBM=  LoadBitmap(hInst,MAKEINTRESOURCE(resource));
	SelectObject(Temp->hImgDC,Temp->hImgBM);

	Temp->x = 0; Temp->y = 0;
	Temp->w = 640; Temp->h = 200;

	Temp->sx = 500; Temp->sy = -70;
	Temp->ex = 2000; Temp->ey = 2000;

	setSpeedX(Temp, 10);
	setSpeedY(Temp, 1);

	return Temp;
}
void Update(BACKGROUND* Obj)
{
	Obj->sx += Obj->speedX;
	if (Obj->sx >= 660) Obj->sx = 0;

	Sleep(1000 / 100);
}
void Render(HDC hdc, BACKGROUND* Obj)
{
	PatBlt(hdc, 0, 0, 640, 480, WHITENESS); //DC를 특정한 조건으로 채우기-->현제는 흰색으로 채움

	BitBlt(hdc, Obj->x, Obj->y, Obj->w, Obj->h, Obj->hImgDC, Obj->sx, Obj->sy, SRCCOPY);

}
void Release(BACKGROUND* Obj)
{
	DeleteObject(Obj->hImgBM);
	ReleaseDC(ghWnd,Obj->hImgDC);
	if (Obj != NULL) free(Obj);

}