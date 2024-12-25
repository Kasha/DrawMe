#pragma once

#include "Base.h"
#include "Point.h"
#include "Circle.h"


template <class U>
class ShapeFactory:public ShapeFactoryBase
{
public:
	ShapeFactory() {};
	virtual ~ShapeFactory() {};
	virtual Base* getShape(char *buffer)
	{ 
		return (*this)(buffer);
	}

	U* operator () (char *buffer)
	{
		if (buffer != NULL)
		{
			return new U(reinterpret_cast<U*>(buffer));
		}

		return NULL;
	}
};

/*Registers Base or Base Derived Class into a Generic Template Functor for 
Creating Right Object when requested according to Object Buffer Rescued from file*/
template <class T>
class BaseFactoryRegistration
{
public:
	//Registers Base or Base Derived Class 
	BaseFactoryRegistration(const char* id)
	{
		BaseFactory::get().registerShapeGenerator(
			id,
			[]() 
			{
				//Creates ShapeFactory Functor with Class T (Type) for converting buffer of chars and creating right Object
				ShapeFactory<T> *pShapeFactory = new ShapeFactory<T>();
				ShapeFactoryBase *pShapeBase = (ShapeFactoryBase*)pShapeFactory;
				//Registers in Class Factory Map id and ShapeFactoryBase Functor for enabling type less Class Factory
				return ShapeFactoryBasePtr(pShapeBase);
			}
		);
	}
};

//Register -  Mapping any type of Base or Base Derived class to id name, and enable creating of ShapeFactory for creation the right Object
#ifndef REGISTER_CLASS
#define REGISTER_CLASS(NAME, TYPE) \
    BaseFactoryRegistration<TYPE> objBase(NAME);
#endif // 