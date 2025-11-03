#include <iostream>
#include <string>

class Animal {
public:
    // 这是一个虚函数
    virtual void speak() {
        std::cout << "Some generic animal sound." << std::endl;
    }
};

class Dog : public Animal {
public:
    // Dog类重写了speak函数
    // C++11 引入了 override 关键字，显式地表明这是一个重写，
    // 如果基类中没有对应的虚函数，编译器会报错，可以防止拼写错误。
    void speak() override {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    // Cat类也重写了speak函数
    void speak() override {
        std::cout << "Meow!" << std::endl;
    }
};

// 这个函数接受一个基类指针，但可以处理任何Animal的派生类
void makeAnimalSpeak(Animal* animal) {
    animal->speak(); // 这里的调用就是多态的体现
}

int main() {
    Animal myAnimal;
    Dog myDog;
    Cat myCat;
    
    // 通过基类指针调用
    std::cout << "Calling through base pointer:" << std::endl;
    Animal* pAnimal = &myAnimal;
    makeAnimalSpeak(pAnimal); // 调用 Animal::speak

    pAnimal = &myDog;
    makeAnimalSpeak(pAnimal); // 调用 Dog::speak

    pAnimal = &myCat;
    makeAnimalSpeak(pAnimal); // 调用 Cat::speak

    return 0;
}
