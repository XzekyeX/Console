#include "main.h"
#include "Console.h"
#include "Text.h"
#include <iomanip>
/**
* @author Zekye
*
*/

int main() {
	Console* console = new Console();
	while (true) {
		console->update();
		Vec2 p = console->getCursorPos();
		println(Text("Cursor ", Color::PINK) << Text(p.strX(), Color::GREEN) << " x " << Text(p.strY(), Color::RED));
	}
	delete console;
	system("pause");
	return 0;
}
