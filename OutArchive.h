#pragma once
#include "Archive.h"

class OutArchive : public Archive
{
public:
	OutArchive() = default;
	~OutArchive() = default;

	void Draw();
	void Deserialization(const string& fileName);
};

