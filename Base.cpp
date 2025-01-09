#include "stdafx.h"
#include "resources.h"

using namespace ShapeMe;

//Register Shape for generic Class Factory (The Only Place where Shape Type is mentioned)
REGISTER_SHAPE(Base);

// Copy constructor
Base::Base(const Base& base)
{
	m_name = base.m_name;
}
// Copy constructor from pointer
Base::Base(const Base*pBase)
{
	m_name = pBase->m_name;
}
// Copy assignment operator
Base& Base::operator=(const Base& other)
{
	if (this != &other) { // Prevent self-assignment
		m_name = other.m_name; // Copy the `m_name` member variable
	}
	return *this;
}

void Base::Draw()
{
	printf("Object Name: %s\n", m_name.c_str());
}