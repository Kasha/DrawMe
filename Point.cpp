#include "stdafx.h"
#include "Point.h"
#include "resources.h"
using namespace ShapeMe;

//Register Shape for generic Class Factory (The Only Place where Shape Type is mentioned)
REGISTER_SHAPE(Point);

// Copy assignment operator
Point& Point::operator=(const Point& other) {
    if (this != &other) { // Prevent self-assignment
        Base::operator=(other); // Assign base class members
        m_x = other.m_x; // Copy member variable m_x
        m_y = other.m_y; // Copy member variable m_y
    }
    return *this;
}

Point::~Point()
{
	//printf("\n\nDestroy Point");
}

void Point::Draw() 
{
	printf("Object Name: %s, Draw: x = %f y = %f\n", m_name.c_str(), m_x, m_y);
}