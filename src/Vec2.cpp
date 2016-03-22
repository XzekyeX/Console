#include "Vec2.h"
/**
* @author Zekye
*
*/
Vec2::Vec2(long x, long y) {
	this->x = x;
	this->y = y;
}

std::ostream& operator<<(std::ostream& str, const Vec2& v) {
	str << "Vec2(" << v.x << "," << v.y << ")";
	return str;
}
