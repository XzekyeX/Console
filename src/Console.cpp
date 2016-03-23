#include "Console.h"
/**
* @author Zekye
*
*/
Console::Console() {
	this->console = GetConsoleWindow();
	this->dc = GetDC(console);
}
Console::~Console() {
	ReleaseDC(console, dc);
}

void Console::update() {
	this->rect = GetLocalCoordinates();
}

void Console::drawPixel(Vec2 pos, COLORREF color) {
	SetPixel(dc, pos.x, pos.y, color);
}

void Console::drawPixel(int x, int y, COLORREF color) {
	SetPixel(dc, x, y, color);
}

RECT Console::GetLocalCoordinates() {
	RECT Rect;
	GetWindowRect(console, &Rect);
	MapWindowPoints(HWND_DESKTOP, GetParent(console), (LPPOINT)&Rect, 2);
	return Rect;
}

Vec2 Console::getConsoleSize() {
	long width = rect.right - rect.left;
	long height = rect.bottom - rect.top;
	return Vec2(width, height);
}

Vec2 Console::getConsolePos() {
	long x = rect.left;
	long y = rect.top;
	return Vec2(x, y);
}

Vec2 Console::getCursorPos() {
	POINT cursor;
	Vec2 pos = getConsolePos();
	Vec2 size = getConsoleSize();
	long cx = 0;
	long cy = 0;
	if (GetCursorPos(&cursor)) {
		cx = cursor.x - pos.x;
		cy = cursor.y - pos.y;
	}
	if (cx <= 0) cx = 0;
	if (cy <= 0) cy = 0;
	if (cx >= size.x) cx = size.x;
	if (cy >= size.y) cy = size.y;
	return Vec2(cx, cy);
}
