#pragma once
#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include <iostream>
using std::cout;
using std::endl;

#include "Shape.h"
#include "IScaleable.h"
#include "MoveableCoords.h"
//класс-наследник Circle
class Circle : public Shape, public IScalable, public MoveableCoords, protected Coords {

protected:
	int r;

public:
	//конструктор по-умолчанию
	Circle(int _x = 0, int _y = 0, int _r = 0, const char* _color = DEFAULT_COLOR) : Shape(_color), Coords(_x, _y), r(_r)
	{
		cout << "Circle(int,int,int)" << endl;
	}

	int GetX() const { return x; }
	int GetY() const { return y; }
	int GetR() const { return r; }

	void SetX(int _x) { x = _x; }
	void SetY(int _y) { y = _y; }
	void SetR(int _r) { r = _r; }

	//вывод круга в консоль
	void draw() const override
	{
		cout << "Circle(" << GetX() << ", " << GetY() << ", " << GetR() << ") " << GetColor() << endl;
	}

	//увеличить круг на factor
	void scale(double factor) override
	{
		r = r * factor;
	}

	//деструктор круга
	~Circle()
	{
		cout << "~Circle()" << endl;
	}
};

#endif // !_CIRCLE_H_

