#include "pch.h"
#include "AnalogClock.h"

/// <summary>
/// Funcion Name = StartMyClock
/// MYCLOCK객체(즉 시계객체)를 생성
/// </summary>
/// <param name="x">좌표</param>
/// <param name="y">좌표</param>
/// <param name="w">너비</param>
/// <param name="h"><높이/param>
/// <returns>시계 객체</returns>
MYCLOCK* StartMyClock(int x, int y, int w, int h)
{
	//메모리에 객체 생성
	MYCLOCK* Temp;//MYCLOCK 포인트변수
	Temp = (MYCLOCK*)malloc(sizeof(MYCLOCK)); //메모리 확보 //MYCLOCK객체 생성
	if (Temp == NULL) return NULL; //객체 생성되면 다음 줄로 아니면 NULL 리턴

	Temp->hdc = NULL;
	Temp->iStyle = CBS_NUM1 | CBS_NUM3 | CBS_NEEDLE2;

	//시계크기 설정
	Temp->x = x;
	Temp->y = y;
	Temp->w = w;
	Temp->h = h;

	//시계 중심좌표 설정
	int cx = Temp->x + (Temp->w / 2); 
	int cy = y + (h / 2);

	//시침,분침,초침 생성
	Temp->pHour = StartNeedle(cx,cy,100,10,RGB(0,0,0));
	Temp->pMin =  StartNeedle(cx,cy,165,5,RGB(0,0, 255));
	Temp->pSec =  StartNeedle(cx,cy,160,1,RGB(255,0,0));

	return Temp; //시계객체 반환
}
/// <summary>
/// Funcion Name = Update
/// MYCLOCK객체의 움직임
/// </summary>
/// <param name="object">MYCLOCK 객체</param>
void Update(MYCLOCK* object)
{
	//float nSecTheta = RAD((float)((object-> gST.wSecond - 22.5f) * 6.0f));
	//gdiRotLineCW(object-> hdc, object->pSec->x, object->pSec->y, object->pSec->length, nSecTheta);
	//float nWinTheta = RAD((float)((gST.wMinute - 22.5f) * 6.0f));
	//gdiRotLineCW(object-> hdc, object->pMin->x, object->pMin->y, object->pMin->length, nWinTheta);
	//float nHourTheta = RAD((float)((object-> gST.wHour - 4.5f) * 6.0f));
	//gdiRotLineCW(object-> hdc, object->pHour->x, object->pHour->y, object->pHour->length, nHourTheta);

	//시계의 외형 디자인
	switch (object->iStyle & 0xF000)
	{
	case CBS_RECT: //사각형
		Rectangle(object->hdc, object->x, object->y,
			object->x + object->w, object->y + object->h);
		break;
	case CBS_CIRCLE: //원형
		Ellipse(object->hdc, object->x, object->y,
			object->x + object->w, object->y + object->h);
		break;
	}

	//시계판의 디자인
	switch (object->iStyle & 0x00FF)
	{
	case CBS_NUM1:
		CBS_Num1(object->hdc, object->pMin->x, object -> pMin->y,object->pMin->length);
		break;
	case CBS_NUM2:
		CBS_Num2(object->hdc, object->pMin->x, object->pMin->y,object->pMin-> length);
		break;
	case CBS_NUM3:
		CBS_Num3(object->hdc, object->pMin->x, object->pMin->y, object->pMin->length);
		break;
	case CBS_NEEDLE1:
		CBS_Needle1(object->hdc, object->pMin->x, object->pMin->y, object->pMin->length);
		break;
	case CBS_NUM1 + CBS_NUM3:
		CBS_Num1(object->hdc, object->pMin->x, object->pMin->y, object->pMin->length);
		CBS_Num3(object->hdc, object->pMin->x, object->pMin->y, object->pMin->length-20);
		break;
	case CBS_NUM2 + CBS_NEEDLE1:
		CBS_Needle1(object->hdc, object->pMin->x, object->pMin->y, object->pMin->length);
		CBS_Num1(object->hdc, object->pMin->x, object->pMin->y, object->pMin->length-20);
		break;
	case CBS_NUM3 + CBS_NEEDLE2:
		CBS_Needle2(object->hdc, object->pMin->x, object->pMin->y, object->pMin->length);
		CBS_Num3(object->hdc, object->pMin->x, object->pMin->y, object->pMin->length + 10);
		break;
	case CBS_NUM1 +CBS_NUM2 + CBS_NEEDLE2:
	default:
		CBS_Num1(object->hdc, object->pMin->x, object->pMin->y, object->pMin->length - 20);
		CBS_Needle2(object->hdc, object->pMin->x, object->pMin->y, object->pMin->length);
		CBS_Num3(object->hdc, object->pMin->x, object->pMin->y, object->pMin->length + 10);
		break;

	}

	//시침 그리기
	SetHDC(object->pHour, object->hdc);//그리는 곳 설정
	SetClock2PI(object->pHour, _CLOCK2PI::T12);//그리는 타입 섷정
	SetTimeNum(object->pHour, object->st.wHour);//그리는 시간 설정
	Update(object->pHour);//시침  움직임 그리는 함수

	//분침 그리기
	SetHDC(object->pMin, object->hdc);
	SetClock2PI(object->pMin, _CLOCK2PI::T60);
	SetTimeNum(object->pMin, object->st.wMinute);
	Update(object->pMin);

	//초침 그리기
	SetHDC(object->pSec, object->hdc);
	SetClock2PI(object->pSec, _CLOCK2PI::T60);
	SetTimeNum(object->pSec, object->st.wSecond);
	Update(object->pSec);
}
void Release(MYCLOCK* object)
{
	Release(object->pSec); //초침 해제
	Release(object->pMin);//분침 해제
	Release(object->pHour); //시침 해제

	if (object == NULL) return;
	free(object); //각체 해제
	object = NULL; //객체 비우기
}
