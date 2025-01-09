#pragma once

#include "BaseFactory.h"


// Generic ShapeFactory for creating and saving shapes via buffer
template <class U>
class ShapeFactory : public ShapeFactoryBase {
public:
	ShapeFactory() = default;
	~ShapeFactory() override = default;

	// Retrieve the shape from a buffer
	Base* getShape(char* buffer) override {
		return (*this)(buffer);
	}

	/** Functor operator for shape creation
   * @brief Creates a shape from the buffer.
   * @param buffer A character buffer containing the shape data.
   * @return A pointer to the created shape of type `U`, or nullptr if the buffer is invalid.
   */
	U* operator()(char* buffer) {
		if (buffer != nullptr) {
			return new U(reinterpret_cast<U*>(buffer));// Copy construct from buffer. Buffer contains the expected object memory
		}
		return nullptr;
	}
};

/**
 * @brief Registers Base or Base Derived Class into a Generic Template Functor for
Creating Right Object when requested according to Object Buffer Rescued from file.
 */
#ifndef REGISTER_SHAPE
#define REGISTER_SHAPE(TYPE)                                              \
   static bool TYPE##_registered = BaseFactory::get().registerShapeGenerator( \
        #TYPE, []() -> ShapeFactoryBasePtr {                              \
            return std::make_shared<ShapeFactory<TYPE>>();                \
        });                                                               \
    static_assert(std::is_base_of<Base, TYPE>::value,                     \
                  "REGISTER_SHAPE can only be used with classes derived from Base");
/*# define REGISTER_CLASS(NAME, TYPE) \
    BaseFactoryRegistration<TYPE> objBase(NAME);*/
#endif // 