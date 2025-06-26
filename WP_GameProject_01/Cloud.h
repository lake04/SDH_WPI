#pragma once

typedef struct ___Cloud
{
	//������Ʈ ��ǥ, ũ��
	int x, y;
	int w, h;
	int speedX;

	//�̹����� ���� ��ǥ, ũ��
	HDC hImgDC;
	HBITMAP hImgBM;
	int sx, sy;
	int ex, ey;
}CLOUD;

CLOUD* StartCloud(HDC hdc, int resource);
void Update(CLOUD* Obj);
void Render(HDC hdc, CLOUD* Obj);
void Release(CLOUD* Obj);

inline int getSpeedX(CLOUD* Obj) { return Obj->speedX; }
inline void setSpeedX(CLOUD* Obj, int speed) { Obj->speedX = speed; }

inline void setX(CLOUD* Obj, int x) { Obj->x = x; }

inline void setY(CLOUD* Obj, int y) { Obj->y = y; }
