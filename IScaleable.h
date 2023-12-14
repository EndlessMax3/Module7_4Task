#pragma once
#ifndef _IScalable_H_
#define _IScalable_H_

//pure abstract class
class IScalable {

public:
	virtual void scale(double factor) = 0; //abstract method
};

#endif