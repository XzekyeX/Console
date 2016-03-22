#include "main.h"
#include "Cursor.h"
/**
* @author Zekye
*
*/
int main() {
	Cursor* cursor = new Cursor();
	while (true) {
		cursor->update();
		Vec2 p = cursor->getCursorPos();
		println("" << p);
	}

	system("pause");
	return 0;
}