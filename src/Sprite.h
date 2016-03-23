#pragma once
#include <FreeImage.h>
#include <ostream>
#include <iostream>
struct Pixel {
	int color;
	friend std::ostream& operator<<(std::ostream& stream, const Pixel& pix) {
		int a = (pix.color >> 24) & 0xff;
		int r = (pix.color >> 16) & 0xff;
		int g = (pix.color >> 8) & 0xff;
		int b = (pix.color >> 0) & 0xff;
		stream << "Pixel[Red=" << r << ", Green=" << g << ", Blue=" << b << ", Alpha=" << a << "]";
		return stream;
	}
};

class Sprite {
private:
	const char* filename;
	Pixel* pixels;
	int width, height;
	BYTE* loadImage(const char* filename, int *width, int *height);
public:
	Sprite(const char* filename);
	int getWidth() const;
	int getHeight() const;
	Pixel* getPixels() const;
};