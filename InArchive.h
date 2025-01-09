#pragma once
#include "Archive.h"

class InArchive: public Archive
{
public:
	InArchive() = default;
	~InArchive() = default;

	void Draw();
	void Serialization(const string& fileName);
};

