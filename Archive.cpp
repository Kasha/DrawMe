#include "stdafx.h"
#include "Archive.h"


Archive::Archive()
{
}


Archive::~Archive()
{
}

void Archive::Add(shared_ptr<Base> obj)
{
	m_objects.push_back(obj);
}