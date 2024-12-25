#pragma once

#include <string>
#include <unordered_map>
#include "BaseFactoryRegistrations.h"

using namespace ShapeMe;
class ShapeFactoryBase
{
public:
	ShapeFactoryBase() {};
	virtual ~ShapeFactoryBase() {}
	//Calls the right ShapeFunctor using polymorphism, and creates the right Shape Object
	virtual Base* getShape(char *buffer) { return NULL; }
};


typedef shared_ptr<ShapeFactoryBase> ShapeFactoryBasePtr;
typedef ShapeFactoryBasePtr(*ShapeInstanceGenerator)();

//Type less Class Factory for creating right object
class BaseFactory
{
public:
	//Retrieves a Single tone instance
	static BaseFactory& get();
	//Registers lambda function which creates ShapeFactoryBase functor and insert it to map according to id (Class name)
	bool registerShapeGenerator(const char* typeName, const ShapeInstanceGenerator& funcCreate);
	//Retrieves ShapeFactoryBase functor according to Class Name (id)
	ShapeFactoryBasePtr getShape(const char* typeName);

private:
	BaseFactory();
	BaseFactory(const BaseFactory&);
	~BaseFactory();
	unordered_map<std::string, ShapeInstanceGenerator> m_generatorsShapes;
};