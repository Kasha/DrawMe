#pragma once
#include <exception>
#include <string>
#include "BaseFactory.h"
#include "InArchive.h"
#include "OutArchive.h"

enum class EXECUTE_MODE : unsigned char
{
	serialization = 's', deserialization = 'd', nothing='n'
};


// Custom exception class for demonstration
class DrawMeException : public std::exception {
public:
	const char* what() const noexcept override {
		return "DrawMeException exception occurred!";
	}
};

struct Params;

// RAII class for cleanup
struct DrawMeClenManager {
	/*Default mode = serialization  in case where no arguments were supplied in command line*/
	
	Archive* p_shapes = nullptr;
	DrawMeClenManager() {
		std::cout << "Initializing resources...\n";
	}

	~DrawMeClenManager() {
		std::cout << "Cleaning up resources...\n";
		delete p_shapes;
		std::cout << "Final cleanup and exit.\n";
	}
};

struct Params
{
	string  s_file_name;
	EXECUTE_MODE e_serialization = EXECUTE_MODE::serialization;
	Params(EXECUTE_MODE serialization = EXECUTE_MODE::serialization, const string& file_name = "out.dat") : e_serialization(serialization), s_file_name(file_name)
	{}
	Params& get(int argc, char** argv) 
	{ 
		string commandline_usage = "usage: DrawMe [-d <file_name> shape filename to deserialize shapes from(default out.dat) \n-s<file_name>shape filename for shapes serialization (default out.dat)]\n";

		if (argc == 1)
		{
			/*Missing arguments*/
			std::cout << commandline_usage;
			e_serialization = EXECUTE_MODE::nothing;
		}
		else if (argc > 1)
		{
			string arg = argv[1];
			
			if (arg == "-h" || arg == "--help")
			{
				std::cout << commandline_usage;
				e_serialization = EXECUTE_MODE::nothing;
			}
			else if (argc > 2)
			{
				if (arg == "-d")
				{
					e_serialization = EXECUTE_MODE::deserialization;

				}
				else
				{
					e_serialization = EXECUTE_MODE::serialization;
				}
				s_file_name = argv[2];
			}
		}
		return *this; }
};