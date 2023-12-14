#pragma once
#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

//класс-родитель Shape
class Shape{
	//int z; //private

private:
	//метод копирования Shape
	void copyRef(const Shape& s)
	{
		this->color = strcpy(new char[strlen(s.color) + 1], s.color);
	}

protected:
	char* color;

public:
	//параметр цвет по-умолчанию
	constexpr const static char* DEFAULT_COLOR = "Black";

	char* GetColor() const { return color; }
	
	//конструктор Shape 
	Shape(const char* _color = DEFAULT_COLOR)
	{
		color = new char[strlen(_color) + 1];
		strcpy(color, _color);
		cout << "Shape(char*)" << endl;
	}
	
	//конструктор копирования
	Shape(const Shape& s)
	{
		copyRef(s);
	}
	
	//оператор копирования
	Shape& operator =(const Shape& s)
	{
		copyRef(s);
		return *this;
	}

	//выводит фигуру в консоль
	virtual void draw() const = 0;
	/* {
		cout << "Shape. " << this->GetColor() << endl;
	}*/

	//деструктор Shape. Очищает память выделенную под color
	virtual ~Shape()
	{
		cout << "~Shape()" << endl;
		delete[] color;
		color = NULL;
	}

};

#endif
