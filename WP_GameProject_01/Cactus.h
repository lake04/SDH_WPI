#pragma once

typedef struct ___Cactus
{
	//오브젝트 좌표, 크기
	int x, y;
	int w, h;
	int speedX;

	//이미지에 대한 좌표, 크기
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
inline void setSpeedX(CACTUS* Obj, int speed) { Obj->speedX = speed; }

inline void setX(CACTUS* Obj, int x) { Obj->x = x; }

