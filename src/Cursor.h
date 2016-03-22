#pragma once
#include <Windows.h>
#include "Vec2.h"
/**
* @author Zekye
*
*/
class Cursor {
private:
	HWND console;
	RECT rect;
	RECT GetLocalCoordinates();
public:
	Cursor();
	void update();
	Vec2 getConsoleSize();
	Vec2 getConsolePos();
	Vec2 getCursorPos();
};