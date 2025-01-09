#include "stdafx.h"
#include "BaseFactory.h"

// Retrieve the ShapeFactoryBase functor for a specific type name
ShapeFactoryBasePtr BaseFactory::getShape(const std::string& typeName) {
    auto it = m_shapeFactoryGenerator.find(typeName);
    if (it != m_shapeFactoryGenerator.end()) {
        return it->second(); // Call the generator function
    }
    return nullptr; // Type name not found
}