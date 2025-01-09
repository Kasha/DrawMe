# DrawMe
Generic serialization/Deserialization of multiple base derived objects.

1. Easy to implement and add new shape.
2. Automatic shape factory registration for each derived base class - REGISTER_SHAPE(TYPE)   
2. BaseFactory - Register a shape generator with a specific type name, using registerShapeGenerator for registration of ShapeFactoryBase
3. Implemented ShapeFactory for creating and Saving Shapes from buffer (serialization/Deserialization to and from file)
4. InArchive and OutArchive for Creating and for serialization/Deserialization to and from file

Three Shapes:
1. Base (Abstract class)
2. Point
3. Circle


Factories:
1. BaseFactory - Singleton Factory for creating shape objects
2. ShapeFactoryBase - Base class for ShapeFactory 
3. ShapeFactory - serialization/Deserialization to and from file. Registered and used as Fuctor and std:: Function, 
using BaseFactory::get().registerShapeGenerator(shape type, ShapeFactory<Type>)
4. REGISTER_SHAPE(TYPE) - Register shape class and compatible ShapeFactory for serialization/Deserialization

Mangers:
1. Archive - Contains Shapes vector. Add Shapes.
2. InArchive - Shape Serialization into file. Draw Shape.
3. OutArchive - Shape Deserialization from file. Draw Shape.

DrawMe.exe in the most generic way it could be done, without using boost Serialization nor Google Prototype Buffer mechanism (both and all solutions, register class type as it can’t be done otherwise in C++)

1.	Shapes aren’t involved in the way they are saved or loaded and file format
2.	Deserialization is the same for any Base Derived class using Class Factory, and Template solution


How To Run:
1. ./DrawMe.exe -h
2. ./DrawMe.exe -s out.dat - Shape Serialization into file
3. ./DrawMe.exe -d out.dat - Shape Deserialization from file.

Running Examples:
PS C:\Dev\DrawMe\x64\Release> ./DrawMe.exe -h
Running main logic...
usage: DrawMe [-d <file_name> shape filename to deserialize shapes from(default out.dat)
-s<file_name>shape filename for shapes serialization (default out.dat)]
Main logic completed successfully.



PS C:\Dev\DrawMe\x64\Release> ./DrawMe.exe -s out.dat
Running main logic...
Object Name: Base
Object Name: Point, Draw: x = 3.200000 y = 4.500000
Object Name: Circle, Draw: radius = 9, x = 7.200000 y = 9.300000
Object Name: Point, Draw: x = 4.500000 y = 7.500000
Object Name: Circle, Draw: radius = 20, x = 1.500000 y = 2.400000
Object Name: Circle, Draw: radius = 22, x = 1.600000 y = 5.400000
Object Name: Circle, Draw: radius = 23, x = 1.700000 y = 6.400000


Finshed Saving and Drawing ThemMain logic completed successfully.

PS C:\Dev\DrawMe\x64\Release> ./DrawMe.exe -d out.dat
Running main logic...
Object Name: Base
Object Name: Point, Draw: x = 3.200000 y = 4.500000
Object Name: Circle, Draw: radius = 9, x = 7.200000 y = 9.300000
Object Name: Point, Draw: x = 4.500000 y = 7.500000
Object Name: Circle, Draw: radius = 20, x = 1.500000 y = 2.400000
Object Name: Circle, Draw: radius = 22, x = 1.600000 y = 5.400000
Object Name: Circle, Draw: radius = 23, x = 1.700000 y = 6.400000


Finshed Loading Shapes and Drawing ThemMain logic completed successfully.
BaseFactoryRegistrations.h

Registers Base or Base Derived Class into a Generic Template Functor for Creating Right Object when requested according to Object Buffer Rescued from file
