#pragma once
#include "Base.h"
#include "Point.h"
#include "Circle.h"
#include <string.h>
#include <vector>
#include <fstream>
#include <iostream>

using namespace ShapeMe;

using base_ptr = shared_ptr<Base>;
using vectorOfPoints = vector<base_ptr>;

class Archive
{
public:
	Archive();
	~Archive() = default;
	void Add(base_ptr obj);
protected:
	vectorOfPoints m_objects;
};

