#include <iostream>

// Shape 是一个抽象基类，因为它含有纯虚函数
class Shape {
public:
    // 纯虚函数，没有函数体
    virtual void draw() = 0;
    
    // 虚析构函数，对于基类来说是一个好习惯
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle: O" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a square: []" << std::endl;
    }
};

int main() {
    // Shape s; // ERROR! 不能创建抽象基类的对象

    Circle c;
    Square s;

    Shape* pShape1 = &c;
    Shape* pShape2 = &s;

    pShape1->draw(); // 调用 Circle::draw()
    pShape2->draw(); // 调用 Square::draw()

    return 0;
}
