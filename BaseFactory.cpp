#include "stdafx.h"
#include "BaseFactory.h"

BaseFactory::BaseFactory()
{
}

BaseFactory::~BaseFactory()
{
}

ShapeFactoryBasePtr BaseFactory::getShape(const char* typeName)
{
	auto it = m_generatorsShapes.find(typeName);
	if (it != m_generatorsShapes.end())
	{
		return it->second();
	}

	return nullptr;
}

bool BaseFactory::registerShapeGenerator(const char* typeName, const ShapeInstanceGenerator& funcCreate)
{
	return m_generatorsShapes.insert(std::make_pair(typeName, funcCreate)).second;
}

BaseFactory & BaseFactory::get()
{
	static BaseFactory instance;
	return instance;
}