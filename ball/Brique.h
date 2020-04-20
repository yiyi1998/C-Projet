#ifndef _BRIQUE
#define _BRIQUE
#include "Body.h"
#include "BodyManager.h"
class Brique : public Body {
public:
	Brique(const string &name, const Box &box, const Position &position, const string &pix, const color c = default_color) : Body(name, box, position, pix), c(c) {}
	void draw();
	void update();
	color getColor();
private:
	color c;
};
class Mbrique: public Brique {
public:
	void update();
	Mbrique(const string &name, const Box &box, const Position &position, const string &pix, const color c = default_color) : Brique(name, box, position, pix,c) {}
};
#endif