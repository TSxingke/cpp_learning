#pragma once
#include <vector>  // 引入 vector 头文件
#include "Student.h" // 引入 Student 类的定义

class StudentManager {
private:
    // 使用 vector 存储 Student 对象
    // 这比我们自己手动 new Student[] 要方便和安全得多
    std::vector<Student> students;

public:
    // 添加一个学生
    // const Student& s 表示我们以“引用”方式传递，避免拷贝整个对象，同时 const 保证不修改它
    void addStudent(const Student& s);

    // 显示所有学生信息
    void showAll() const;

    // --- 新增功能：文件读写 ---
    
    // 将所有学生信息保存到指定文件
    // filename: 文件名 (例如 "data.txt")
    void saveToFile(const std::string& filename) const;

    // 从指定文件加载学生信息
    void loadFromFile(const std::string& filename);

    // 根据序号排序学生
    void sortStudentsByID();
};

