#include "stdafx.h"
#include "InArchive.h"


void InArchive::Draw()
{
	for (auto &i : m_objects)
	{
		i.get()->Draw();
	}
}

void InArchive::Serialization(const string& fileName)
{
	ofstream oFile(fileName.c_str(), ios::binary);
	for (auto &i : m_objects)
	{
		Base *pB = i.get();
		size_t sz = pB->Size();
		oFile.write((char *)&sz, sizeof(size_t));
		oFile.write((char *)pB, sz);
	}
	oFile.close();
}