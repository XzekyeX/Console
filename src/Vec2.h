#pragma once
#include <iostream>
#include <sstream>
/**
* @author Zekye
*
*/
class Vec2 {
public:
	long x, y;
	Vec2(long x, long y);
	friend std::ostream& operator<<(std::ostream& os, const Vec2& v);

	inline std::string strX() const {
		std::stringstream stream;
		stream << x;
		return stream.str();
	}

	inline std::string strY() const {
		std::stringstream stream;
		stream << y;
		return stream.str();
	}
};