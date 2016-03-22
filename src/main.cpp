#include "main.h"
#include "Cursor.h"
#include "Text.h"
/**
* @author Zekye
*
*/

int main() {
	Cursor* cursor = new Cursor();
	while (true) {
		cursor->update();
		Vec2 p = cursor->getCursorPos();
		println(Text("Cursor ", Color::YELLOW) << Text(p.strX(), Color::GREEN) << " x " << Text(p.strY(), Color::RED));
	}
	system("pause");
	return 0;
}
