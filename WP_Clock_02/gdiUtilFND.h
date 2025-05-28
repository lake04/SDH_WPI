#pragma once

void gdi7Segment(HDC hdc, int x, int y, char segment, int scale = 2);

void Zero(HDC hdc, int x, int y, int s = 2);
void One(HDC hdc, int x, int y, int s = 2);
void Two(HDC hdc, int x, int y, int s = 2);
void Three(HDC hdc, int x, int y, int s = 2);
void Four(HDC hdc, int x, int y, int s = 2);
void Five(HDC hdc, int x, int y, int s = 2);
void Six(HDC hdc, int x, int y, int s = 2);
void Seven(HDC hdc, int x, int y, int s = 2);
void Eight(HDC hdc, int x, int y, int s = 2);
void Nine(HDC hdc, int x, int y, int s = 2);

void gdiFND_Number(HDC hdc, int x, int y, int scale, int n);
void gdiFND_Numbers(HDC hdc, int x, int y, int scale, unsigned int number);



