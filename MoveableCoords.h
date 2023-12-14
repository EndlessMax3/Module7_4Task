#pragma once
#ifndef _MoveableCoords_H_
#define _MoveableCoords_H_
#include "IMoveable.h"

class MoveableCoords : public IMoveable {


public:

	virtual int GetX() const = 0;
	virtual int GetY() const = 0;
	virtual void SetX(int x) = 0;
	virtual void SetY(int y) = 0;
	void moveBy(int dx, int dy)
	{
		SetX(GetX() + dx);
		SetY(GetY() + dy);
	}
};
#endif