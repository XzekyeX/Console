#include "Console.h"
/**
* @author Zekye
*
*/
Console::Console() {
	this->console = GetConsoleWindow();
	this->dc = GetDC(console);
	this->handle = GetStdHandle(STD_OUTPUT_HANDLE);
}
 
Console::~Console() {
	ReleaseDC(console, dc);
}

void Console::update() {
	this->rect = GetLocalCoordinates();
}

void Console::drawPixel(Vec2 pos, COLORREF color) {
	drawPixel(pos.x, pos.y, color);
}

void Console::drawPixel(int x, int y, COLORREF color) {
	SetPixel(dc, x, y, color);
}

void Console::drawRect(int x, int y, int w, int h, int b, COLORREF color) {
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < b; j++) {
			drawPixel(x + i, y + j, color);
		}
	}
	for (int i = 0; i < w + b; i++) {
		for (int j = 0; j < b; j++) {
			drawPixel(x + i, y + h + j, color);
		}
	}
	for (int i = 0; i < h + b; i++) {
		for (int j = 0; j < b; j++) {
			drawPixel(x + j, y + i, color);
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < b; j++) {
			drawPixel(x + w + j, y + i, color);
		}
	}
}

void Console::fillRect(int x, int y, int w, int h, COLORREF color) {
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			drawPixel(x + i, y + j, color);
		}
	}
}

void Console::drawSprite(const Sprite& sprite, int px, int py) {
	for (int x = 0; x < sprite.getWidth(); x++) {
		for (int y = 0; y < sprite.getHeight(); y++) {
			int color = sprite.getPixels()[x + y * sprite.getWidth()].color;
			//int a = (color >> 24) & 0xff;
			int r = (color >> 16) & 0xff;
			int g = (color >> 8) & 0xff;
			int b = (color >> 0) & 0xff;
			drawPixel(px + x, py + y, RGB(r, g, b));
		}
	}
}
void Console::drawSprite(const Sprite& sprite, int px, int py, int scale) {
	for (int x = 0; x < sprite.getWidth() * scale; x++) {
		for (int y = 0; y < sprite.getHeight() * scale; y++) {
			int color = sprite.getPixels()[(x / scale) + (y / scale) * sprite.getWidth()].color;
			//int a = (color >> 24) & 0xff;
			int r = (color >> 16) & 0xff;
			int g = (color >> 8) & 0xff;
			int b = (color >> 0) & 0xff;
			drawPixel(px + x, py + y, RGB(r, g, b));
		}
	}
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
