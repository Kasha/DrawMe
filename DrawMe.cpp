// DrawMe.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Defines.h"




int main(int argc, char **argv)
{
	try {
		std::cout << "Running main logic...\n";
		auto [s_file_name, e_serialization] = Params().get(argc, argv);
		
		if (e_serialization == EXECUTE_MODE::serialization)
		{
			Base p("Base");//Just example, no need of move assignment in this program
			Base p1(std::move(p));
			//Save
			//Add Add 1 Base and 4 Shapes
			InArchive objects;
			objects.Add(make_shared<Base>());
			objects.Add(make_shared<Point>(3.2f, 4.5f));
			objects.Add(make_shared<Circle>(7.2f, 9.3f, 9));
			objects.Add(make_shared<Point>(4.5f, 7.5f));
			objects.Add(make_shared<Circle>(1.5f, 2.4f, 20));
			objects.Add(make_shared<Circle>(1.6f, 5.4f, 22));
			objects.Add(make_shared<Circle>(1.7f, 6.4f, 23));
			//Save to out.dat binary file
			objects.Serialization("out.dat");

			//Draw InArchive list
			objects.Draw();
			std::cout << "\n\nFinshed Saving and Drawing Them";
		}
		else if (e_serialization == EXECUTE_MODE::deserialization)
		{
			//Load
			OutArchive objects;
			objects.Deserialization("out.dat");
			objects.Draw();
			std::cout << "\n\nFinshed Loading Shapes and Drawing Them";
		}

		std::cout << "Main logic completed successfully.\n";
		char c = getchar();
		
		return 0;  // Exit with success code
	}
	catch (const DrawMeException& e) {
		std::cerr << "Caught CustomException: " << e.what() << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << "Caught std::exception: " << e.what() << "\n";
	}
	catch (...) {
		std::cerr << "Caught an unknown exception.\n";
	}

	char c = getchar();
	return 1;  // Exit with error code
}

