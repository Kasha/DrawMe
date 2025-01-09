#pragma once

#include <string>
#include <unordered_map>
#include <functional>
#include "Base.h"

using namespace ShapeMe;


// Base class for ShapeFactory
class ShapeFactoryBase {
public:
	virtual ~ShapeFactoryBase() = default;

	// Polymorphic method to retrieve a shape from a buffer
	virtual Base* getShape(char* buffer) = 0;
};

using ShapeFactoryBasePtr = std::shared_ptr<ShapeFactoryBase>;
using ShapeFactoryGenerator = std::function<ShapeFactoryBasePtr()>;



// Singleton Factory for creating shape objects
class BaseFactory {
public:
    // Retrieve the singleton instance
    static BaseFactory& get() {
        static BaseFactory instance; // Lazy initialization with thread-safety
        return instance;
    }

   /**
     * @brief Register a shape generator for a specific type name.
     * @param typeName The name of the type to register.
     * @param funcShapeCreate The factory generator function.
     * @return True if the generator was successfully registered; false if the type already exists.
     */
    bool registerShapeGenerator(const std::string& typeName, const ShapeFactoryGenerator& funcShapeCreate) {
        auto [iter, inserted] = m_shapeFactoryGenerator.try_emplace(typeName, funcShapeCreate);
        return inserted;
    }

    /**
    * @brief Retrieve the ShapeFactoryBase functor for a specific type name.
    * @param typeName The name of the type to retrieve.
    * @return A shared pointer to the ShapeFactoryBase, or nullptr if not found.
    */
    ShapeFactoryBasePtr getShape(const std::string& typeName) ;

private:
    BaseFactory() = default;
    ~BaseFactory() = default;

    // Prevent copying and assignment
    BaseFactory(const BaseFactory&) = delete;
    BaseFactory& operator=(const BaseFactory&) = delete;

    // Map for storing type-name to ShapeInstanceGenerator mappings
    std::unordered_map<std::string, ShapeFactoryGenerator> m_shapeFactoryGenerator;
};
