# PropertyClass
The Property class is a C++ class designed to represent properties with various types and values. It provides a flexible way to define and manage properties in software systems.

Features
Define properties with specific types, names, start bytes, and lengths.
Dynamically set and retrieve property values of any type.
Support for copy and move constructors, assignment operators, and type-safe getters.
Compatible with the Boost.Any library for type-erased value storage.
Usage
To use the Property class in your C++ project, follow these steps:

Include the "Property.hpp" header file in your source code.
Create instances of the Property class using the constructor with parameters for type, name, start byte, and length.
Use the setValue() method to set the value of a property.
Use the getValue() method to retrieve the value of a property.
Optionally, use the template getter method get<>() for type-safe value retrieval.

    #include "Property.hpp"
    #include <iostream>
    
    int main() {
        // Create a Property object
        Property prop(1, "example_property", 0, 4);
    
        // Set the value of the property
        prop.setValue(42);
    
        // Print the value of the property
         std::cout << prop << std::endl;
    
        return 0;
    }
