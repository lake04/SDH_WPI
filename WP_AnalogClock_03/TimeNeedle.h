#pragma once
enum _CLOCK2PI { T12, T24, T60 };

typedef struct __timeneedle
{
	HDC hdc;
	_CLOCK2PI c2pi;
	int timeNum;

	int x, y; //시작 좌표
	int length; //바늘 길이

	HPEN color; //색

}NEEDLE;

//StartNeedle구조채의 매소드 (맴버 함수)
NEEDLE* StartNeedle(int x, int y, int length, int thick, COLORREF rgb);
void Update(NEEDLE* object); //객체 동작 함수
void Release(NEEDLE* object);//객테 해제 함수

inline void SetTimeNum(NEEDLE* object, int num) { object->timeNum = num; }
inline void SetClock2PI(NEEDLE* object, _CLOCK2PI c2pi) { object->c2pi = c2pi; }
inline void SetHDC(NEEDLE* object, HDC hdc) { object->hdc = hdc; }

