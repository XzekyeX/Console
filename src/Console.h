#pragma once
#include <Windows.h>
#include "Vec2.h"
#include "Text.h"
#include "Sprite.h"
/**
* @author Zekye
*
*/
class Console {
private:
	HWND console;
	HANDLE handle;
	HDC dc;
	RECT rect;
	RECT GetLocalCoordinates();
public:
	Console();
	~Console();
	void update();
	void drawPixel(Vec2 pos, COLORREF color);
	void drawPixel(int x, int y, COLORREF color);
	void drawRect(int x, int y, int w, int h, int b, COLORREF color);
	void fillRect(int x, int y, int w, int h, COLORREF color);
	void drawSprite(const Sprite& sprite, int x, int y);
	void drawSprite(const Sprite& sprite, int x, int y, int scale);
	Vec2 getConsoleSize();
	Vec2 getConsolePos();
	Vec2 getCursorPos();
};