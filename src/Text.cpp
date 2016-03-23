#include "Text.h"
/**
* @author Zekye
*
*/
Text::Text(string text, Color color, HANDLE handle) {
	this->text = text;
	this->color = color;
	this->handle = handle;
	if (this->handle == NULL) this->handle = GetStdHandle(STD_OUTPUT_HANDLE);
}

string Text::getText() const {
	return text;
} 

Color Text::getColor() const {
	return color;
}

ostream& operator<<(ostream& stream, Text& text) {
	if (text.handle == NULL) text.handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(text.handle, text.color);
	stream << text.getText().c_str();
	SetConsoleTextAttribute(text.handle, Color::WHITE);
	return stream;
}