#pragma once
#include "Point.h"

using namespace ShapeMe;

class Circle : public Point
{
public:
	Circle(float x = 0, float y = 0, unsigned int r = 0, string name = "Circle");
	Circle(Circle& circle);
	Circle(Circle* pCircle);

	virtual ~Circle();

	virtual void Draw();
	size_t Size() 
	{ 
		return sizeof(*this); 
	}
private:
	unsigned int m_r;
};

