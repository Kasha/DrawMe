#pragma once
#include "Base.h"

using namespace ShapeMe;
class Point : public Base
{
public:
	Point(float x = 0, float y = 0, string name = "Point");
	Point(Point& point);
	Point(Point* pPoint);
	virtual ~Point();
	virtual void Draw();
	virtual size_t Size() 
	{ 
		return sizeof(*this);
	}
protected:
	float m_x;
	float m_y;
};


