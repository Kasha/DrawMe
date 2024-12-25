#pragma once
#include "Base.h"
#include "Point.h"
#include "Circle.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace ShapeMe;

typedef vector<shared_ptr<Base>> vectorOfPoints;

class Archive
{
public:
	Archive();
	~Archive();

	void Add(shared_ptr<Base> obj);
protected:
	vectorOfPoints m_objects;
};

