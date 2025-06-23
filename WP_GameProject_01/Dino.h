#pragma once

typedef struct ___Dino
{
	//������Ʈ ��ǥ,ũ��
	int x, y;
	int w, h;
	bool bIsJump;

	//�̹����� ���� ��ǥ, ũ��
	HDC hImgDC;
	HBITMAP hImgBM;
	int sx, sy;
	int ex, ey;


}DINO;

DINO* StartDino(HDC hdc, int resource);
void Update(DINO* Obj);
void Render(HDC hdc, DINO* Obj);
void Release(DINO* Obj);

inline bool getJump(DINO* Obj) { return Obj->bIsJump; };
inline bool setJump(DINO* Obj, bool jump) { return Obj->bIsJump = jump; };