#include "stdafx.h"
#include "Archive.h"


Archive::Archive()
{
	m_objects.reserve(10);
}


void Archive::Add(base_ptr obj)
{
	m_objects.push_back(obj);
}
