#pragma once
#include <Windows.h>
#include <string>
#include <ostream>
#include <iostream>
using namespace std;

enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

/**
* @author Zekye
*
*/
class Text {
private:
	HANDLE handle;
	string text;
	Color color;
public:
	Text(string text, Color color, HANDLE handle = 0);
	string getText() const;
	Color getColor() const;
	friend ostream& operator<<(ostream& stream, Text& text);
};