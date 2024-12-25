#include "stdafx.h"
#include "BaseFactory.h"
#include "Circle.h"

using namespace ShapeMe;

//Register Shape for generic Class Factory (The Only Place where Shape Type is mentioned)
REGISTER_CLASS("Circle", Circle);

Circle::Circle(float x, float y, unsigned int r, string name) : Point(x, y, name)
{
	m_r = r;
}

Circle::Circle(Circle& circle) : Point(circle)
{
	m_r = circle.m_r;
}

Circle::Circle(Circle* pCircle) : Point(pCircle)
{
	m_r = pCircle->m_r;
}

Circle::~Circle()
{
	//printf("\n\nDestroy Circle");
}

void Circle::Draw()
{
	printf("Object Name: %s, Draw: radius = %d, x = %f y = %f \n", m_name.c_str(), m_r, m_x, m_y);
}