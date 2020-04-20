#include "pch.h"
#include "Brique.h"
short vx1 = 1;
void Brique::draw() {
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
void Brique::update() {
	if (disabled == true) {
		for (unsigned  int i = 0; i < box.height ; i++) {
			for(unsigned int j=0; j< box.width ; j++)
			bodyManager->getConsole().clear((position.x)+j,(position.y)+i);
		}
	}
}
color Brique::getColor() {
	return (this->c);
}
void Mbrique::update() {
	if (judge == 1)
	{
		disabled = true;
		for (unsigned int i = 0; i < box.height; i++) {
			for (unsigned int j = 0; j < box.width; j++)
				bodyManager->getConsole().clear((position.x) + j, (position.y) + i);
		}
	}
	else {
		if (disabled == true) {
			for (unsigned int i = 0; i < box.height; i++) {
				for (unsigned int j = 0; j < box.width; j++)
					bodyManager->getConsole().clear((position.x) + j, (position.y) + i);
			}
		}
		else {
			Body* pt1 = this;
			Body** pt2 = &(pt1);
			unsigned short px = position.x;
			unsigned short py = position.y;
			unsigned int n = 0;
			px = px + vx1;
			if (!(bodyManager->moveBody(*this, Position(px, py), pt2)))
				if (((*pt2)->getName() == "leftBorder") || ((*pt2)->getName() == "rightBorder"))
					vx1 = -vx1;
				else if ((*pt2)->getName() == "ball")
					disabled = true;
		}
	}
}