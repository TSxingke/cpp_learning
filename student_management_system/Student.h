#pragma once // 这是一个现代C++中防止头文件被重复包含的指令，非常常用

#include <string>

class Student {
private:
    int studentID;
    std::string name;
    int age;

public:
    // --- 声明 ---
    Student(int id, const std::string& name, int age);
    
    int getID() const;
    std::string getName() const;
    int getAge() const;

    void display() const;
};
