#ifndef _BALL
#define _BALL
#include "Body.h"
#include "BodyManager.h"
class Ball : public Body {
public:
	Ball(const string &name, const Box &box, const Position &position, const string &pix, short vx, short vy, const color& c = default_color) : Body(name, box, position, pix), vx(vx), vy(vy), c(c), numOfbriques(0) {}
	void draw();
	void update();
private:
	color c;
	short vx;
	short vy;
	int numOfbriques;
};
#endif