#include "pch.h"
#include "TimeNeedle.h"

/// <summary>
/// Function Name :   StartNeddle
/// 아날로그 시계바늘구조체를 객체로 생성하는 함수
/// </summary>
/// <param name="x">중십위치 좌표</param>
/// <param name="y">중심위치 좌표</param>
/// <param name="length">길이</param>
/// <param name="thick">두께</param>
/// <param name="rgb">색</param>
/// <returns>시계바늘 객체를 메모리 생성후 포인터로 반환</returns>
NEEDLE* StartNeedle(int x,int y,int length,int thick,COLORREF rgb)
{
	//메모리 객체생성
	NEEDLE* Temp; //NEEDLE포인터 변수
	Temp = (NEEDLE*)malloc(sizeof(NEEDLE)); //NEEDLE 객체 생성
	if (Temp == NULL) return NULL; //생성이 되었으면 실행안함

	Temp->hdc = NULL;
	Temp->c2pi = _CLOCK2PI::T12; //기본값을 시침로 셋팅
	
	Temp -> x = x;
	Temp -> y = y;
	Temp->length = length;
	Temp->color = CreatePen(PS_SOLID,thick,rgb); //선의 해당하는 펜을 만듬

	return Temp; //생성된 객체 반환
}

/// <summary>
/// Function Name = Update
/// NEEDLE객체가 움직이도록 하는 함수
/// </summary>
/// <param name="object">NEEDLE 객체</param>
void Update(NEEDLE* object)
{
	float fTheta = 0.f; //각도

	//시계바늘의 속성에 따라 각도 설정
	switch (object->c2pi)
	{
	case _CLOCK2PI::T12: //12시간 360도로 도는 각
		fTheta = RAD((float)((object->timeNum - 4.5) * 30.0f));
			break;
	case _CLOCK2PI::T60: //60분초 360도로 도는 각
		fTheta = RAD((float)((object->timeNum -22.5) * 6.0f));
			break;
	}

	HPEN oldPen = (HPEN)SelectObject(object->hdc, object->color); //펜 선택
	gdiRotLineCW(object->hdc, object->x,object->y, object->length,fTheta); //그리는 함수
	SelectObject(object->hdc, oldPen); //펜 반환

}

/// <summary>
/// Function Name = Release
/// NEEDLE객체를 메모리에사 해체/제거하는 함수
/// </summary>
/// <param name="object"></param>
void Release(NEEDLE* object) 
{
	DeleteObject(object->color); // 지정된 팬 제거
	if (object == NULL) return; //오브젝트가 없을 때 리턴, 있으면 다음 줄로 넘어감
	free(object); //메모리에서 NEEDLE개체 제거
	object = NULL; //메모리들어있는 가능성 마저 지움(완전 소멸 느깜)
}
