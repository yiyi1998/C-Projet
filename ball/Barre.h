#ifndef _BARRE
#define _BARRE
#include "Body.h"
#include "BodyManager.h"
class Barre : public Body {
public:
	Barre(const string &name, const Box &box, const Position &position, const string &pix, const color& c = default_color) : Body(name, box, position, pix), c(c) {}
	void draw();
	void update();
private:
	color c;
};
#endif