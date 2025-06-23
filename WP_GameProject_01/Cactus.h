#pragma once

typedef struct ___Cactus
{
	//������Ʈ ��ǥ,ũ��
	int x, y;
	int w, h;
	int speedX;

	//�̹����� ���� ��ǥ, ũ��
	HDC hImgDC;
	HBITMAP hImgBM;
	int sx, sy;
	int ex, ey;
}CACTUS;

CACTUS* StartCactus(HDC hdc, int resource);
void Update(CACTUS* Obj);
void Render(HDC hdc, CACTUS* Obj);
void Release(CACTUS* Obj);

inline int getSpeedX(CACTUS* Obj) { return Obj->speedX; }
inline int setSpeedX(CACTUS* Obj, int speed) { return Obj->speedX = speed; }

inline void setX(CACTUS* Obj, int x) { Obj->x = x; }
