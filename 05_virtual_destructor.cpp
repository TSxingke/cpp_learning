#include <iostream>

class Base {
public:
    Base() { std::cout << "Base Constructor\n"; }
    // 试着注释掉下面的 virtual 关键字，看看会发生什么
    virtual ~Base() { std::cout << "Base Destructor\n"; }
};

class Derived : public Base {
private:
    int* p_data;
public:
    Derived() {
        p_data = new int[10]; // 在堆上申请了一些内存
        std::cout << "Derived Constructor (memory allocated)\n";
    }
    ~Derived() {
        delete[] p_data; // 在析构时释放内存
        std::cout << "Derived Destructor (memory freed)\n";
    }
};

int main() {
    Base* p = new Derived(); // 创建一个派生类对象，用基类指针指向它
    
    // ... do something with p ...

    delete p; // 通过基类指针删除对象

    return 0;
}
