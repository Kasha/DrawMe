#pragma once
#include "Point.h"

using namespace ShapeMe;

class Circle : public Point
{
public:
	// Default constructor
	Circle(float x = 0, float y = 0, unsigned int r = 0, const string& name = "Circle") : Point(x, y, name), m_r(r) {};
	// Copy constructor from pointer
	Circle(const Circle& circle);
	// Copy constructor from pointer
	Circle(const Circle* pCircle);
	
	// Move constructor
	Circle(Circle&& other) noexcept
		: Point(std::move(other)), m_r(other.m_r) {
		other.m_r = 0; // Reset radius in the moved-from object
	}

	// Copy assignment operator
	Circle& operator=(const Circle& other);

	// Move assignment operator
	Circle& operator=(Circle&& other) noexcept {
		if (this != &other) { // Prevent self-assignment
			Point::operator=(std::move(other)); // Move base class members
			m_r = other.m_r;                   // Move radius
			other.m_r = 0;                     // Reset radius in the moved-from object
		}
		return *this;
	}


	virtual ~Circle() override;

	void Draw() override;
	size_t Size() override
	{ 
		return sizeof(*this); 
	}
private:
	unsigned int m_r;
};

