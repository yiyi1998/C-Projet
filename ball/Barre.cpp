#include "pch.h"
#include "Barre.h"
void Barre::draw() {
	bodyManager->getConsole().set_pen_color(c);
	if (requestDraw) requestDraw = false;
	else {
		if (prevPosition != position) {
			for (unsigned short line = 0; line < box.height; line++) {
				bodyManager->getConsole().put_string(string(box.width, ' '), prevPosition.x, prevPosition.y + line);
			}
			prevPosition = position;
		}
	}
	for (unsigned short line = 0; line < box.height; line++) {
		bodyManager->getConsole().put_string(pix.substr(line*box.width, box.width), position.x, position.y + line);
	}

}
void Barre::update()
{

	if (GetAsyncKeyState(VK_RIGHT) && position.x < 50)
		position.x += 2;
	if (GetAsyncKeyState(VK_LEFT) && position.x > 5)
		position.x -= 2;
	Sleep(25);
}