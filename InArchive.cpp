#include "stdafx.h"
#include "InArchive.h"

InArchive::InArchive()
{
}


InArchive::~InArchive()
{
}

void InArchive::Draw()
{
	for (auto &i : m_objects)
	{
		i.get()->Draw();
	}
}

void InArchive::Serialization(char *fileName)
{
	ofstream oFile(fileName, ios::binary);
	for (auto &i : m_objects)
	{
		Base *pB = i.get();
		size_t sz = pB->Size();
		oFile.write((char *)&sz, sizeof(size_t));
		oFile.write((char *)pB, sz);
	}
	oFile.close();
}