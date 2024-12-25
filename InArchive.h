#pragma once
#include "Archive.h"

class InArchive: public Archive
{
public:
	InArchive();
	~InArchive();

	void Draw();
	void Serialization(char *fileName);
};

