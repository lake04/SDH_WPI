//#include "pch.h"
#include "gdiUtilFND.h"

/*
void gdi7Segment(HDC hdc, int x, int y, char segment, int scale)
{
	int thickness = 5;
	int sY = scale;
	int sX = (int)(sY * 0.6f);
	switch (segment)
	{
	case 'a': gdiLine(hdc, x + 1 * sX, y + 1 * sY, x + 9 * sX, y + 1 * sY); break;
	case 'b': gdiLine(hdc, x + 9 * sX, y + 1 * sY, x + 9 * sX, y + 5 * sY); break;
	case 'c': gdiLine(hdc, x + 9 * sX, y + 5 * sY, x + 9 * sX, y + 9 * sY); break;
	case 'd': gdiLine(hdc, x + 1 * sX, y + 9 * sY, x + 9 * sX, y + 9 * sY); break;
	case 'e': gdiLine(hdc, x + 1 * sX, y + 5 * sY, x + 1 * sX, y + 9 * sY); break;
	case 'f': gdiLine(hdc, x + 1 * sX, y + 1 * sY, x + 1 * sX, y + 5 * sY); break;
	case 'g': gdiLine(hdc, x + 1 * sX, y + 5 * sY, x + 9 * sX, y + 5 * sY); break;
	}
}
//*/

void gdi7Segment(HDC hdc, int x, int y, char segment, int scale)
{
	int fullH = 100 * scale;                        // 전체 높이
	int fullW = (int)(fullH * 0.6);                 // 세로:가로 = 1:0.6 비율
	int thickness = 10 * scale;                    // 세그먼트 두께 비례 조절

	int ox = x;
	int oy = y;

	switch (segment)
	{
	case 'a': // 상단 가로
		Rectangle(hdc, ox + thickness, oy, ox + fullW - thickness, oy + thickness);
		break;
	case 'b': // 오른쪽 상단 세로
		Rectangle(hdc, ox + fullW - thickness, oy + thickness, ox + fullW, oy + fullH / 2 - thickness / 2);
		break;
	case 'c': // 오른쪽 하단 세로
		Rectangle(hdc, ox + fullW - thickness, oy + fullH / 2 + thickness / 2, ox + fullW, oy + fullH - thickness);
		break;
	case 'd': // 하단 가로
		Rectangle(hdc, ox + thickness, oy + fullH - thickness, ox + fullW - thickness, oy + fullH);
		break;
	case 'e': // 왼쪽 하단 세로
		Rectangle(hdc, ox, oy + fullH / 2 + thickness / 2, ox + thickness, oy + fullH - thickness);
		break;
	case 'f': // 왼쪽 상단 세로
		Rectangle(hdc, ox, oy + thickness, ox + thickness, oy + fullH / 2 - thickness / 2);
		break;
	case 'g': // 가운데 가로
		Rectangle(hdc, ox + thickness, oy + fullH / 2 - thickness / 2, ox + fullW - thickness, oy + fullH / 2 + thickness / 2);
		break;
	}
}



void Zero(HDC hdc, int x, int y, int s)
{
	gdi7Segment(hdc, x, y, 'a', s);
	gdi7Segment(hdc, x, y, 'b', s);
	gdi7Segment(hdc, x, y, 'c', s);
	gdi7Segment(hdc, x, y, 'd', s);
	gdi7Segment(hdc, x, y, 'e', s);
	gdi7Segment(hdc, x, y, 'f', s);
}

void One(HDC hdc, int x, int y, int s)
{
	gdi7Segment(hdc, x, y, 'b', s);
	gdi7Segment(hdc, x, y, 'c', s);
}

void Two(HDC hdc, int x, int y, int s)
{
	gdi7Segment(hdc, x, y, 'a', s);
	gdi7Segment(hdc, x, y, 'b', s);
	gdi7Segment(hdc, x, y, 'g', s);
	gdi7Segment(hdc, x, y, 'e', s);
	gdi7Segment(hdc, x, y, 'd', s);
}

void Three(HDC hdc, int x, int y, int s)
{
	gdi7Segment(hdc, x, y, 'a', s);
	gdi7Segment(hdc, x, y, 'b', s);
	gdi7Segment(hdc, x, y, 'g', s);
	gdi7Segment(hdc, x, y, 'c', s);
	gdi7Segment(hdc, x, y, 'd', s);
}

void Four(HDC hdc, int x, int y, int s)
{
	gdi7Segment(hdc, x, y, 'f', s);
	gdi7Segment(hdc, x, y, 'g', s);
	gdi7Segment(hdc, x, y, 'b', s);
	gdi7Segment(hdc, x, y, 'c', s);
}

void Five(HDC hdc, int x, int y, int s)
{
	gdi7Segment(hdc, x, y, 'a', s);
	gdi7Segment(hdc, x, y, 'f', s);
	gdi7Segment(hdc, x, y, 'g', s);
	gdi7Segment(hdc, x, y, 'c', s);
	gdi7Segment(hdc, x, y, 'd', s);
}

void Six(HDC hdc, int x, int y, int s)
{
	gdi7Segment(hdc, x, y, 'a', s);
	gdi7Segment(hdc, x, y, 'f', s);
	gdi7Segment(hdc, x, y, 'g', s);
	gdi7Segment(hdc, x, y, 'e', s);
	gdi7Segment(hdc, x, y, 'c', s);
	gdi7Segment(hdc, x, y, 'd', s);
}

void Seven(HDC hdc, int x, int y, int s)
{
	gdi7Segment(hdc, x, y, 'a', s);
	gdi7Segment(hdc, x, y, 'b', s);
	gdi7Segment(hdc, x, y, 'c', s);
}

void Eight(HDC hdc, int x, int y, int s)
{
	gdi7Segment(hdc, x, y, 'a', s);
	gdi7Segment(hdc, x, y, 'b', s);
	gdi7Segment(hdc, x, y, 'c', s);
	gdi7Segment(hdc, x, y, 'd', s);
	gdi7Segment(hdc, x, y, 'e', s);
	gdi7Segment(hdc, x, y, 'f', s);
	gdi7Segment(hdc, x, y, 'g', s);
}

void Nine(HDC hdc, int x, int y, int s)
{
	gdi7Segment(hdc, x, y, 'a', s);
	gdi7Segment(hdc, x, y, 'b', s);
	gdi7Segment(hdc, x, y, 'c', s);
	gdi7Segment(hdc, x, y, 'd', s);
	gdi7Segment(hdc, x, y, 'f', s);
	gdi7Segment(hdc, x, y, 'g', s);
}

typedef void (*NumFunc)(HDC, int, int, int); //함수의 포인터 정의

//함수의 포인터 설정
NumFunc gNumFuncs[10] = {
	Zero,One, Two, Three, Four, Five, Six, Seven, Eight, Nine
};

void gdiFND_Number(HDC hdc, int x, int y, int scale, int n)
{
	if (n >= 0 && n <= 9)
	{
		gNumFuncs[n](hdc, x, y, scale); //함수의 포인터 사용
	}
}

void gdiFND_Numbers(HDC hdc, int x, int y, int scale, unsigned int number)
{
	if (number > INT_MAX) //숫자 크기 제한
	{
		//printf("%d 이상의 숫자는 출력하지 않습니다.", INT_MAX);
		return;
	}

	TCHAR strBuff[128]; //숫자 출력 문자열
	int  nSize; //숫자 크기
	wsprintf(strBuff, L"%d", number); //숫자를 문자열로 저장
	nSize = wcslen(strBuff); //숫자가 변환된 문자열의 크기 구하기

	int seedNum = 1; //시작이 1의 자리
	int i;
	for (i = 0; i < nSize - 1; i++) seedNum *= 10; //10진수 자리수 만큼 곱하기 
	int* num;
	num = (int*)malloc(nSize * sizeof(int)); //메모리 확보를 해줘(nSize의 수 만큼 int형 ==> int형 배열 nSize만큼)

	int digitWidth = (int)(scale * 60);            // 한 숫자의 가로 폭
	int space = (int)(digitWidth * 1.1f);
	//문자화된 숫자를 다시 한 숫자씩 포인터num(num 배열)에 하나씩 저장
	for (i = 0; i < nSize; i++)
	{
		num[i] = number / seedNum; //포인터 배열 num에 하나씩 숫자 저장
		number %= seedNum; //큰 수를 줄인 수를 돌려주기
		seedNum /= 10; //자리수 줄이기 

		gdiFND_Number(hdc, x + i * space, y, scale, num[i]); //숫자 출력
	}
}

