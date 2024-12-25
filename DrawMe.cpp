// DrawMe.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "BaseFactory.h"
#include "InArchive.h"
#include "OutArchive.h"


int main(int argc, char **argv)
{
	if (argc > 1)
	{
		//Load
		OutArchive objects;
		objects.Deserialization("out.dat");
		objects.Draw();

		printf("\n\nFinshed Loading Shapes and Drawing Them");
		getchar();
	}
	else
	{
		//Save
		//Add Add 1 Base and 4 Shapes
		InArchive objects;
		objects.Add(make_shared<Base>());
		objects.Add(make_shared<Point>(3.2f, 4.5f));
		objects.Add(make_shared<Circle>(7.2f, 9.3f, 9));
		objects.Add(make_shared<Point>(4.5f, 7.5f));
		objects.Add(make_shared<Circle>(1.5f, 2.4f, 20));
	
		//Save to out.dat binary file
		objects.Serialization("out.dat");

		//Draw InArchive list
		objects.Draw();

		printf("\n\nFinshed Saving Shapes and Drawing Them");
		getchar();
	}

    return 0;
}

