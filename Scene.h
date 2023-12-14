#pragma once
#include "Shape.h"
#include "IScaleable.h"
#include "IMoveable.h"
#include <iostream>

const int MAX_SCENE_SIZE = 100; //����������� ������ ������������� �������
//����� �����
class Scene {

private:
	Shape** objects; //������ �������� Shape
	int size; //������ �������

public:
	Scene() : size(0) { objects = new Shape * [MAX_SCENE_SIZE]; } //�������� ������ ��� ������ ������� MAX_SCENE_SIZE
	//���������� �������, ������� ������ ���������� ��� ������
	~Scene()
	{
		clear();
		delete[] objects; 
	}

	//���������� ������ �� ������� Scene
	void draw()
	{
		cout << "************ Drawing Scene ************" << endl;
		for (int i = 0; i < size; i++)
		{
			objects[i]->draw();
		}
		cout << "***************************************" << endl;
	}

	void scale(double factor)
	{
		for (int i = 0; i < size; i++)
		{
			IScalable* sc = dynamic_cast<IScalable*>(objects[i]);
			if (sc != NULL)
				sc->scale(factor);
		}
	}

	void moveBy(int dx, int dy)
	{
		for (int i = 0; i < size; i++)
		{
			IMoveable* mv = dynamic_cast<IMoveable*>(objects[i]);
			if (mv != NULL)
				mv->moveBy(dx,dy);
		}
	}

	//�������� ������ � ������ Scene
	void add(Shape* s) 
	{
		if (size < MAX_SCENE_SIZE)
			objects[size++] = s;
		else
			std::cerr << "Array size is too big" << endl; //����� ������ ��� ���������� ����� 100 �����
	}

	//������� ������ ���������� ��� ������
	void clear()
	{
		for (int i = 0; i < size; i++)
		{
			delete objects[i];
		}
		size = 0;
	}

};
