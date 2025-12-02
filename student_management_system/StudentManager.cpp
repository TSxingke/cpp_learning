#include "StudentManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>

void StudentManager::addStudent(const Student& s) {
    // vector 的 push_back 方法可以将元素添加到数组的末尾
    // 任务：请调用 students 的 push_back 方法将 s 添加进去
    students.push_back(s);
}

void StudentManager::showAll() const {
    std::cout << "--- Student List ---" << std::endl;
    // 任务：请使用 for 循环 (可以是范围 for 循环) 遍历 students 向量
    // 并调用每个 student 对象的 display() 方法
    // 提示： 
    // for (const auto& stu : students) { ... }
    for (const auto& stu : students) {
        stu.display();
    }
}

void StudentManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file for writing." << std::endl;
        return;
    }
    else{
        for (const auto& stu : students) {
            file << stu.getID() << " " << stu.getName() << " " << stu.getAge() << std::endl;
        }
        file.close();
        std::cout << "Students data saved to " << filename << std::endl;
    }
}

void StudentManager::loadFromFile(const std::string& filename){
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file for reading." << std::endl;
        return;
    }
    else{
        // 清空当前数据，防止重复加载
        students.clear();
        
        int id;
        std::string name;
        int age;
        while (file >> id >> name >> age) {
            Student stu(id, name, age);
            students.push_back(stu);
        }
        file.close();
        std::cout << "Students data loaded from " << filename << std::endl;
    }
}

void StudentManager::sortStudentsByID(){
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b){
        return a.getID() < b.getID();
    });
    std::cout << "Students sorted by ID." << std::endl;
}

