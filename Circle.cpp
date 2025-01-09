#include "stdafx.h"
#include "Circle.h"
#include "resources.h"

using namespace ShapeMe;


REGISTER_SHAPE(Circle);

// Copy constructor
Circle::Circle(const Circle& circle) : Point(circle)
{
	m_r = circle.m_r;
}
// Copy constructor from pointer
Circle::Circle(const Circle* pCircle) : Point(pCircle)
{
	m_r = pCircle->m_r;
}

// Copy assignment operator
Circle& Circle::operator=(const Circle& other) {
	if (this != &other) { // Prevent self-assignment
		Point::operator=(other); // Copy base class members
		m_r = other.m_r;         // Copy radius
	}
	return *this;
}

Circle::~Circle()
{
	//printf("\n\nDestroy Circle");
}

void Circle::Draw()
{
	printf("Object Name: %s, Draw: radius = %d, x = %f y = %f \n", m_name.c_str(), m_r, m_x, m_y);
}