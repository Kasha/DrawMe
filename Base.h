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
		// Default constructor
		Base(const string& name = "Base") : m_name(name) {};
		// Copy constructor
		Base(const Base& base);
		// Copy constructor from pointer
		Base(const Base*pBase);
		// Move constructor
		Base(Base&& other) noexcept : m_name(std::move(other.m_name)) {
			// Optionally reset the moved-from object's state
			other.m_name = "";
		}

		// Copy assignment operator
		Base& operator=(const Base& other);

		// Move assignment operator
		Base& operator=(Base&& other) noexcept {
			if (this != &other) {
				m_name = std::move(other.m_name);
				// Optionally reset the moved-from object's state
				other.m_name = "";
			}
			return *this;
		}
		virtual ~Base() = default;
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