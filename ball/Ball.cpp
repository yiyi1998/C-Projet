#include "pch.h"
#include "Ball.h"
int numdoublebrique = 0;
int judge = 0;
int acceler = 0;
void Ball::draw() {
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
void Ball::update() {

	Body* pt1 = this;
	Body** pt2 = &(pt1);
	unsigned short px = position.x;
	unsigned short py = position.y;
	unsigned int n = 0;
	px = px + (this->vx);
	py = py - (this->vy);
	if ((this->numOfbriques) == 8) {
		string sw = "You win !!!";
		this->bodyManager->quit();
		this->bodyManager->getConsole().clear();
		this->bodyManager->getConsole().set_pen_color(green);
		this->bodyManager->getConsole().put_string(sw, 30, 20);
	}
	else {
		if (!(bodyManager->moveBody(*this, Position(px, py), pt2)))
		{
			if ((*pt2)->getName() != "abyss")
			{
				if ((*pt2)->getName() == "brique") {
					(this->numOfbriques)++;
					if ((*pt2)->getColor() == yellow)
					{
						(*pt2)->disabled = true;
						if ((((*pt2)->getPosition().x == px) && ((*pt2)->getPosition().y == py)) || (((*pt2)->getPosition().x + ((*pt2)->getBox().width) - 1 == px) && ((*pt2)->getPosition().y == py)) || (((*pt2)->getPosition().x == px) && (((*pt2)->getPosition().y + ((*pt2)->getBox().height)) - 1 == py)) || (((*pt2)->getPosition().x + ((*pt2)->getBox().width) - 1 == px) && (((*pt2)->getPosition().y + ((*pt2)->getBox().height)) - 1 == py)))
						{
							(this->vx) = -(this->vx);
							(this->vy) = -(this->vy);
						}
						else {
							if (((*pt2)->getPosition().x < px) && (((*pt2)->getPosition().x + (*pt2)->getBox().width - 1) > px))
							{
								(this->vy) = -(this->vy);
							}
							else
							{
								if (((*pt2)->getPosition().y < py) && (((*pt2)->getPosition().y + (*pt2)->getBox().height - 1) > py))
									(this->vx) = -(this->vx);
							}
						}
						acceler=1;
					}
					else
					{
						if ((*pt2)->getColor() == blue) {
							if(numdoublebrique ==1) (*pt2)->disabled = true;
							else numdoublebrique++;
							if ((((*pt2)->getPosition().x == px) && ((*pt2)->getPosition().y == py)) || (((*pt2)->getPosition().x + ((*pt2)->getBox().width) - 1 == px) && ((*pt2)->getPosition().y == py)) || (((*pt2)->getPosition().x == px) && (((*pt2)->getPosition().y + ((*pt2)->getBox().height)) - 1 == py)) || (((*pt2)->getPosition().x + ((*pt2)->getBox().width) - 1 == px) && (((*pt2)->getPosition().y + ((*pt2)->getBox().height)) - 1 == py)))
							{
								(this->vx) = -(this->vx);
								(this->vy) = -(this->vy);
							}
							else {
								if (((*pt2)->getPosition().x < px) && (((*pt2)->getPosition().x + (*pt2)->getBox().width - 1) > px))
								{
									(this->vy) = -(this->vy);
								}
								else
								{
									if (((*pt2)->getPosition().y < py) && (((*pt2)->getPosition().y + (*pt2)->getBox().height - 1) > py))
										(this->vx) = -(this->vx);
								}
							}
						}
						else
						{
							(*pt2)->disabled = true;
							if ((((*pt2)->getPosition().x == px) && ((*pt2)->getPosition().y == py)) || (((*pt2)->getPosition().x + ((*pt2)->getBox().width) - 1 == px) && ((*pt2)->getPosition().y == py)) || (((*pt2)->getPosition().x == px) && (((*pt2)->getPosition().y + ((*pt2)->getBox().height)) - 1 == py)) || (((*pt2)->getPosition().x + ((*pt2)->getBox().width) - 1 == px) && (((*pt2)->getPosition().y + ((*pt2)->getBox().height)) - 1 == py)))
							{
								(this->vx) = -(this->vx);
								(this->vy) = -(this->vy);
							}
							else {
								if (((*pt2)->getPosition().x < px) && (((*pt2)->getPosition().x + (*pt2)->getBox().width - 1) > px))
									(this->vy) = -(this->vy);
								else
								{
									if (((*pt2)->getPosition().y < py) && (((*pt2)->getPosition().y + (*pt2)->getBox().height - 1) > py))
										(this->vx) = -(this->vx);
								}
							}
						}
					}
				}
				else {
					if ((*pt2)->getName() != "barre") {
						if (((*pt2)->getName() == "leftCoin") || ((*pt2)->getName() == "rightCoin")) {
							if (((*pt2)->getPosition().x == px) && ((*pt2)->getPosition().y == py))
							{
								(this->vx) = -(this->vx);
								(this->vy) = -(this->vy);
							}
						}
						else
							if (((*pt2)->getName() == "leftBorder") || ((*pt2)->getName() == "rightBorder"))
							{
								(this->vx) = -(this->vx);
							}
							else
								if ((*pt2)->getName() == "upsideBorder")
									(this->vy) = -(this->vy);
					}
					else {
						if (vx = -1)
						{
							if (px == ((*pt2)->getPosition().x + static_cast <short>(3))) {
								(this->vx) = 0;
								(this->vy) = -(this->vy);
							}
							else {
								if (px < ((*pt2)->getPosition().x + static_cast <short>(3)))
								{
									(this->vy) = static_cast <short>(1);
								}
								else
								{
									(this->vx) = static_cast <short>(1);
									(this->vy) = static_cast <short>(1);
								}
							}
						}
						else
						{
							if (vx = 1) {
								if (px == ((*pt2)->getPosition().x + static_cast < short>(4))) {
									(this->vx) = 0;
									(this->vy) = -(this->vy);
								}
								else {
									if (px < ((*pt2)->getPosition().x + static_cast <short>(4)))
									{
										(this->vy) = static_cast <short>(1);
										(this->vx) = static_cast <short>(-1);
									}
									else
									{
										(this->vy) = static_cast <short>(1);
										(this->vx) = static_cast <short>(1);
									}
								}

							}
							else
							{
								if (px == ((*pt2)->getPosition().x + 4)) {
									(this->vx) = 0;
									(this->vy) = -(this->vy);
								}
								else {
									if (px < ((*pt2)->getPosition().x + 4))
									{
										(this->vy) = 1;
										(this->vx) = -1;
									}
									else
									{
										(this->vx) = 1;
										(this->vy) = 1;
									}
								}
							}
						
						/*{ if (px == ((*pt2)->getPosition().x + ((*pt2)->getBox().width-1)/2)){
							vx = 0;
							vy = 1;
						}
						else if (px < ((*pt2)->getPosition().x + ((*pt2)->getBox().width - 1) / 2))
						{
							vx = -2;
							vy = 1;
						}
						else {
							vx = 2;
							vy = 1;
						}*/
						}
					}
				}
			}
			else {
				string sl = "You lose !!!";
				judge = 1;
				this->bodyManager->quit();
				this->bodyManager->getConsole().clear();
				this->bodyManager->getConsole().set_pen_color(red);
				this->bodyManager->getConsole().put_string(sl, 22, 20);

			}
		}
	}
}