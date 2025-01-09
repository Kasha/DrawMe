#pragma once
#include "Base.h"

using namespace ShapeMe;
class Point : public Base
{
public:
	// Default constructor
	Point(float x = 0, float y = 0, const std::string& name = "Point")
		: Base(name), m_x(x), m_y(y) {}

	// Copy constructor
	Point(const Point& point)
		: Base(point), m_x(point.m_x), m_y(point.m_y) {}

	// Copy constructor from pointer
	Point(const Point* pPoint)
		: Base(pPoint), m_x(pPoint ? pPoint->m_x : 0), m_y(pPoint ? pPoint->m_y : 0) {}

    // Move constructor
    Point(Point&& other) noexcept
        : Base(std::move(other)), m_x(other.m_x), m_y(other.m_y) {
        // Reset the moved-from object's state
        other.m_x = 0;
        other.m_y = 0;
    }

    // Copy assignment operator
    Point& operator=(const Point& other);

    // Move assignment operator
    Point& operator=(Point&& other) noexcept {
        if (this != &other) {
            Base::operator=(std::move(other)); // Call base class move assignment
            m_x = other.m_x;
            m_y = other.m_y;

            // Reset the moved-from object's state
            other.m_x = 0;
            other.m_y = 0;
        }
        return *this;
    }

	~Point() override;
	void Draw() override;
	size_t Size() override
	{ 
		return sizeof(*this);
	}
protected:
	float m_x;
	float m_y;
};


