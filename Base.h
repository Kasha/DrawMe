#pragma once
#include <string>
#include <memory>

using namespace std;
namespace ShapeMe
{
	//Abstract Base class
	class Base
	{
	public:
		Base(string name = "Base");
		Base(Base& base);
		Base(Base*pBase);
		virtual ~Base();
		virtual void Draw();
		virtual size_t Size() 
		{ 
			return sizeof(*this); 
		}
		string GetName()  { return m_name; }
	protected:
		string m_name;
	};
}