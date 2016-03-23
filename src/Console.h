#pragma once
#include <Windows.h>
#include "Vec2.h"
/**
* @author Zekye
*
*/
class Console {
private:
	HWND console;
	HDC dc;
	RECT rect;
	RECT GetLocalCoordinates();
public:
	Console();
	~Console();
	void update();
	void drawPixel(Vec2 pos, COLORREF color);
	void drawPixel(int x, int y, COLORREF color);
	Vec2 getConsoleSize();
	Vec2 getConsolePos();
	Vec2 getCursorPos();
};