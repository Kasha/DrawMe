#include "stdafx.h"
#include "OutArchive.h"
#include "BaseFactory.h"

OutArchive::OutArchive()
{
}

OutArchive::~OutArchive()
{
}

void OutArchive::Draw()
{
	for (auto &i : m_objects)
	{
		//Draw Proper shape using virtual Draw
		i.get()->Draw();
	}
}

void OutArchive::Deserialization(char *fileName)
{
	ifstream iFile(fileName, ios::binary);
	if (iFile.is_open())
	{
		size_t sz;
		
		do
		{
			//Get saved object size
			iFile.read((char*)&sz, sizeof(size_t));
			if (iFile)
			{
				char *p = new char[sz];
				if (size_t(sz) > 0)
				{
					/*Reconstructs shape from file in a generic way based on REGISTER_CLASS shape
					I’m using buffer twice, once for creating Base obj for 
					retrieving name and secondly for creating the right type object according to name*/

					//Read size buffer of char
					iFile.read(reinterpret_cast<char*>(p), sz);
					if (iFile)
					{
						//Create Base Class from buffer
						Base *pB = new Base(reinterpret_cast<Base*>(p));
						//Create generator Shape functor for creating right shape according to name
						ShapeFactoryBasePtr obj = BaseFactory::get().getShape(pB->GetName().c_str());
						/*getShape retrieves a ShapeFactoryBasePtr obj functor according to pB->name.
						obj uses virtual getShape with buffer of chars and uses shape functor generator to create the right shape*/
						Add(shared_ptr<Base>(obj->getShape(p)));
						//Delete buffer
						delete pB;				
					}
				}
				delete[] p;
			}
		}
		while (iFile);

		iFile.close();
	}
}