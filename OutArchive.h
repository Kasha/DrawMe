#pragma once
#include "Archive.h"

class OutArchive : public Archive
{
public:
	OutArchive();
	~OutArchive();

	void Draw();
	void Deserialization(char *fileName);
};

