# CreatureLib

## Overview
CreatureLib is a modern C++ library designed to demonstrate advanced usage of templates, smart pointers, and polymorphism through a creature management system. This project not only showcases the implementation of a template-based storage system but also exemplifies best practices in C++ coding, CMake build configuration, and project organization.

## Features
Template-Based Design: Utilizes C++ templates to create a flexible storage mechanism for managing polymorphic objects.
Smart Pointer Usage: Demonstrates the use of std::unique_ptr for memory management, emphasizing modern C++ memory safety features.
Polymorphism: Implements a polymorphic creature hierarchy to showcase dynamic polymorphism and abstract base classes.
CMake Integration: Leverages CMake for project configuration, building, and dependency management, highlighting modern best practices in build system setup.
Getting Started
Prerequisites
C++17 compliant compiler (e.g., GCC, Clang, MSVC)
CMake version 3.15 or higher
## Building the Project
Clone the repository:

bash
Copy code
git clone https://github.com/yourusername/CreatureLib.git
cd CreatureLib
Create a build directory and configure the project:

bash
Copy code
mkdir build && cd build
cmake ..
Build the project:

bash
Copy code
cmake --build .
## Usage
The library provides a CreatureFactory for creating instances of Human and Animal classes, which are derived from the abstract Creature base class. Here's a quick example of how to use the library:

cpp
Copy code
#include "CreatureFactory.h"
#include "DemoLib.h"

int main() {
    Core::DemoLib<Creature> creatureStorage;
    auto human = CreatureFactory::create(CreatureType::HUMAN);
    auto animal = CreatureFactory::create(CreatureType::ANIMAL);

    creatureStorage.addToStorage(std::move(human));
    creatureStorage.addToStorage(std::move(animal));

    std::cout << "Storage contains " << creatureStorage.getStorageSize() << " creatures.\n";
    return 0;
}
## Project Structure
/include: Contains all header files for the library.
/src: Source files implementing the library's functionality.
/examples: Example applications demonstrating the use of the library.
CMakeLists.txt: Root CMake configuration file.
## Design Considerations
Memory Management: The library makes extensive use of std::unique_ptr to ensure automatic cleanup of dynamically allocated objects, reducing the risk of memory leaks and pointer dangling.
Extensibility: The use of polymorphism and templates allows for easy extension of the creature types and storage mechanisms without modifying existing code.
Build System: CMake is utilized for its powerful cross-platform build capabilities, making it easy to integrate the library into other projects.
## Contributing
We welcome contributions! Please read our CONTRIBUTING.md file for guidelines on how to make a contribution.

## License
This project is licensed under the MIT License - see the LICENSE file for details.


