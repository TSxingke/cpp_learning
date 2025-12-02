#include <iostream>
#include <string>
#include "StudentManager.h"

int main() {
    StudentManager manager;
    manager.loadFromFile("data.txt");

    int choice;

    while (true) {
        std::cout << "\n=== Student Management System ===" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Show All Students" << std::endl;
        std::cout << "3. Save to File" << std::endl;
        std::cout << "4. Load from File" << std::endl;
        std::cout << "5. Sort Students by ID" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // --- 任务：完成添加学生的逻辑 ---
                // 1. 声明变量 id, age 和 name
                // 2. 提示用户输入这些信息 (std::cin >> ...)
                // 3. 创建一个 Student 对象
                // 4. 调用 manager.addStudent() 将其添加
                int id;
                int age;
                std::string name;

                std::cout << "Enter the student's ID: ";
                std::cin >> id;
                std::cout << "Enter the student's name: ";
                std::cin >> name;
                std::cout << "Enter the student's age: ";
                std::cin >> age;

                Student student(id, name, age);
                manager.addStudent(student);
                
                std::cout << "Student added successfully!" << std::endl;
                break;
            }
            case 2:
                manager.showAll();
                break;
            case 3:
                manager.saveToFile("data.txt");
                break;
            case 4:
                manager.loadFromFile("data.txt");
                break;
            case 5:
                manager.sortStudentsByID();
                break;
            case 0:
                manager.saveToFile("data.txt");
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
        }
    }

    return 0;
}

