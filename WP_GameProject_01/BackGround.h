#pragma once

typedef struct ___Background
{
	//������Ʈ ��ǥ,ũ��
	int x, y;
	int w, h;
	int speedX, speedY; //��� ��ü �����̴� �ӵ�

	//�̹����� ���� ��ǥ, ũ��
	HDC hImgDC;
	HBITMAP hImgBM;
	int sx, sy;
	int ex, ey;


}BACKGROUND;

BACKGROUND* StartBackground(HDC hdc, int resource);
void Update(BACKGROUND* Obj);
void Render(HDC hdc, BACKGROUND* obj);
void Release(BACKGROUND* Obj);

inline int getSpeedX(BACKGROUND* Obj) { return Obj->speedX; }
inline int getSpeedY(BACKGROUND* Obj) { return Obj->speedY; }
inline int setSpeedX(BACKGROUND* Obj, int speed) { return Obj->speedX = speed; }
inline int setSpeedY(BACKGROUND* Obj, int speed) { return Obj->speedY = speed; }
