#include "main.h"

/**
* @author Zekye
*
*/

int main() {
	Console* console = new Console();
	Sprite grass("textures/grass.png");
	Sprite sand("textures/sand.png"); 
	while (true) {
		console->drawSprite(grass, 128, 128, 2);
		console->drawSprite(sand, 256, 128, 2);
		//console->drawRect(128, 128, 128, 128, 4, RGB(255, 128, 0));
		//console->fillRect(300, 128, 128, 128, RGB(128, 255, 0));
		//	console->update();
		//	Vec2 p = console->getCursorPos();
		//	println(Text("Cursor ", Color::PINK) << Text(p.strX(), Color::GREEN) << " x " << Text(p.strY(), Color::RED));
	}
	delete console;
	system("pause");
	return 0;
}
