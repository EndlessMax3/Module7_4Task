#pragma once
#ifndef _IMoveable_H_
#define _IMoveable_H_

//pure abstract class
class IMoveable {

public:
	virtual void moveBy(int, int) = 0; //abstract method
};

#endif