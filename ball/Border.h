#ifndef _BORDER
#define _BORDER
#include "Body.h"
#include "BodyManager.h"
class Border : public Body {
public:
	Border(const string &name, const Box &box, const Position &position, const string &pix, const color& c = default_color) : Body(name, box, position, pix),  c(c) {}
	void draw();
private:
	color c;
};
#endif
