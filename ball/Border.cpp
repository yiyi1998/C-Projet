#include "pch.h"
#include "Border.h"
void Border::draw() {
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