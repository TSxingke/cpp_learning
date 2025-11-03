#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor called." << std::endl;
    }
    ~Base() {
        std::cout << "Base destructor called." << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived constructor called." << std::endl;
    }
    ~Derived() {
        std::cout << "Derived destructor called." << std::endl;
    }
};

int main() {
    std::cout << "Creating a Derived object..." << std::endl;
    Derived d;
    std::cout << "Derived object created." << std::endl;
    
    std::cout << "Program is about to end. Object will be destroyed." << std::endl;
    return 0;
}
