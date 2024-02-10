#ifndef DEMOLIB_H
#define DEMOLIB_H

#include "demoLib_global.h"
#include <iostream>

namespace {
void helperFunc(){
    std::cout << "asking for help" <<std::endl;
    }
}

// Template class, implementation in the .h file.
namespace Core{
template <typename T>
    class DEMOLIB_EXPORT DemoLib
    {
    public:
        DemoLib() {};
        void printMe(){
            helperFunc();
            std::cout <<"ahha";
        };
        // Permanently move ownership of the item to the storage vector
        void addToStorage(std::unique_ptr<T> item)
            {
            storage.push_back(std::move(item));
        };

        int getStorageSize() const
        {
            return storage.size();
        }
    private:
        // Create a storage vector for any class
        std::vector<std::unique_ptr<T>> storage;
    };
}

#endif // DEMOLIB_H
