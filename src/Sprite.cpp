#include "Sprite.h"

Sprite::Sprite(const char* filename) {
	this->filename = filename;
	this->pixels = (Pixel*)loadImage(filename, &width, &height);
	if (!pixels || pixels == nullptr) std::cout << "Failed to load image! Filename: " << filename << std::endl;
}

BYTE* Sprite::loadImage(const char* filename, int *width, int *height) {
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	FIBITMAP *dib = nullptr;
	fif = FreeImage_GetFileType(filename, 0);
	if (fif == FIF_UNKNOWN) fif = FreeImage_GetFIFFromFilename(filename);
	if (fif == FIF_UNKNOWN) return nullptr;
	if (FreeImage_FIFSupportsReading(fif)) dib = FreeImage_Load(fif, filename);
	if (!dib) return nullptr;
	BYTE* result = FreeImage_GetBits(dib);
	*width = FreeImage_GetWidth(dib);
	*height = FreeImage_GetHeight(dib);
	if ((result == 0) || (width == 0) || (height == 0)) return nullptr;
	return result;
}


int Sprite::getWidth() const {
	return width;
}

int Sprite::getHeight() const {
	return height;
}

Pixel* Sprite::getPixels() const {
	return pixels;
}