#include "Coords.h"

ostream& operator <<(ostream& s, const Coords& c)
{
	return s << "(" << c.x << ", " << c.y << ")";
}