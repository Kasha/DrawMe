#include "stdafx.h"
#include "Base.h"
#include "BaseFactory.h"

using namespace ShapeMe;

//Register Shape for generic Class Factory (The Only Place where Shape Type is mentioned)
REGISTER_CLASS("Base", Base);

Base::Base(string name) : m_name(name)
{
}

Base::Base(Base& base)
{
	m_name = base.m_name;
}

Base::Base(Base*pBase)
{
	m_name = pBase->m_name;
}

Base::~Base()
{
	//printf("\n\nDestroy Base");
}

void Base::Draw()
{
	printf("Object Name: %s\n", m_name.c_str());
}