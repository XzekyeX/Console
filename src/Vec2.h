#pragma once
#include <iostream>
/**
* @author Zekye
*
*/
class Vec2 {
public:
	long x, y;
	Vec2(long x, long y);
	friend std::ostream& operator<<(std::ostream& os, const Vec2& v);
};