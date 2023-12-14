#pragma once
#ifndef _LINE_H_
#define _LINE_H_
#include <iostream>
using std::cout;
using std::endl;

#include "Shape.h"
#include "IScaleable.h"
#include "IMoveable.h"

//класс-наследник Line
class Line : public IScalable /*should be first for VS*/, public IMoveable, public Shape {

protected:
	Coords c1, c2;

public:
	//конструктор класса Line
	Line(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0, const char* _color = DEFAULT_COLOR) : Shape(_color)
	{
		c1 = Coords(_x1, _y1);
		c2 = Coords(_x2, _y2);
		cout << "Line(int,int,int,int)" << endl;
	}

	int GetX1() const { return c1.x; }
	int GetY1() const { return c1.y; }
	int GetX2() const { return c2.x; }
	int GetY2() const { return c2.y; }

	Line* SetX1(int _x) { c1.x = _x; return this; }
	Line* SetY1(int _y) { c1.y = _y; return this; }
	Line* SetX2(int _x) { c2.x = _x; return this; }
	Line* SetY2(int _y) { c2.y = _y; return this; }

	//отобразить линию в консоли
	void draw() const override
	{
		//this->Shape::draw(); вызов метода родителя
		cout << "Line(" << GetX1() << ", " << GetY1() << ") "<< '(' << GetX2() << ", " << GetY2() << ") " << GetColor() << endl;
	}

	//сместить линию на dx1, dy1, dx2, dy2
	void moveBy(int dx = 0, int dy = 0) override
	{
		c1.movBy(dx, dy);
		c2.movBy(dx, dy);
	}

	//увеличить линию на factor
	void scale(double factor) override
	{
		SetX2((GetX2() - GetX1()) * factor + GetX1());
		SetY2((GetY2() - GetY1()) * factor + GetY1());
	}

	//деструктор линии
	~Line()
	{
		cout << "~Line()" << endl;
	}
};

#endif // !_LINE_H_

