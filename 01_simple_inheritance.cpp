#include <iostream>
#include <string>

// --- 基类 (Base Class) ---
// 定义了一个通用的“人”类
class Person {
public:
    // 成员变量
    std::string name;
    int age;

    // 成员函数
    void sayHello() {
        std::cout << "Hello, my name is " << name << " and I am " << age << " years old." << std::endl;
    }
};

// --- 派生类 (Derived Class) ---
// Student 公有继承自 Person
// 语法： class 派生类名 : 继承方式 基类名
class Student : public Person {
public:
    // Student 类特有的成员变量
    int studentID;

    // Student 类特有的成员函数
    void study() {
        // 可以直接访问从 Person 继承来的 public 成员 name
        std::cout << name << " is studying." << std::endl;
    }
};

int main() {
    // 创建一个 Student 对象
    Student student1;

    // --- 访问继承来的成员 ---
    // 为从 Person 继承来的成员赋值
    student1.name = "Li Ming";
    student1.age = 18;

    // --- 访问自己的成员 ---
    // 为 Student 特有的成员赋值
    student1.studentID = 1001;

    // 调用从 Person 继承来的方法
    student1.sayHello(); // 输出: Hello, my name is Li Ming and I am 18 years old.

    // 调用 Student 特有的方法
    student1.study(); // 输出: Li Ming is studying.

    return 0;
}
