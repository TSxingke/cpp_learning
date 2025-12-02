#include "Student.h" // 包含对应的头文件
#include <iostream>

// --- 实现 ---
// 构造函数
Student::Student(int id, const std::string& name, int age)
    : studentID(id), name(name), age(age) {
    // 构造函数的函数体，这里为空，因为所有工作都在初始化列表中完成了
}

// getID 的实现
int Student::getID() const {
    return studentID;
}

// 请你在这里完成 getName(), getAge() 和 display() 的实现
std::string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

void Student::display() const {
    std::cout << "ID: " << studentID << ",Name: " << name << ",Age: " << age << std::endl;
}