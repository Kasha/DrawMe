#include "stdafx.h"
#include "BaseFactory.h"
#include "Point.h"

using namespace ShapeMe;

//Register Shape for generic Class Factory (The Only Place where Shape Type is mentioned)
REGISTER_CLASS("Point", Point);

Point::Point(float x, float y, string name) : Base(name)
{
	m_x = x;
	m_y = y;
}

Point::Point(Point& point) : Base(point)
{
	m_x = point.m_x;
	m_y = point.m_y;
}
Point::Point(Point* pPoint) : Base(pPoint)
{
	m_x = pPoint->m_x;
	m_y = pPoint->m_y;
}

Point::~Point()
{
	//printf("\n\nDestroy Point");
}

void Point::Draw() 
{
	printf("Object Name: %s, Draw: x = %f y = %f\n", m_name.c_str(), m_x, m_y);
}