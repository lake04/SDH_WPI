#pragma once

#define CBS_RECT	0x1000
#define CBS_CIRCLE  0x2000
#define CBS_NUM1	0x0001
#define CBS_NUM2	0x0002
#define CBS_NUM3	0x0004
#define CBS_NEEDLE1	0x0010
#define CBS_NEEDLE2 0x0020

//시게를 만드는 구조체
typedef struct __analogclock
{
	HDC hdc;
	SYSTEMTIME st; //시간구조체 //시스템시간을 저장

	int iStyle; //시계 스타일

	int x, y; //시계 좌표
	int w, h; //시계 크기
	NEEDLE* pHour; //시침
	NEEDLE* pMin;  //분침
	NEEDLE* pSec;  //초침

}MYCLOCK;

//MYCLOCK구조채의 매소드 (맴버 함수)
MYCLOCK* StartMyClock(int x, int y, int w, int h); //객체 생성 함수
void Update(MYCLOCK* object); //객체 동작 함수
void Release(MYCLOCK* object); //객체 해제 함수

inline void SetTime(MYCLOCK* object, SYSTEMTIME st) { object->st = st; }
inline void SetHDC(MYCLOCK* object, HDC hdc) { object->hdc = hdc; }
inline void SetBK(MYCLOCK* object, int iStyle) { object->iStyle - iStyle; }
