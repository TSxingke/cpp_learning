#include <iostream>
#include <string>

// --- 基类 (Base Class) ---
// 定义了一个通用的“人”类
class Person {
public:
    Person(const std::string& name, int age) :name(name), age(age) {}
    // 成员函数
    virtual void sayHello() = 0;
    void setName(const std::string& newName) {
        name = newName;
    }
    void setAge(int newAge) {
        age = newAge;
    }

    virtual ~Person() {
        std::cout << name << " is destroyed." << std::endl;
    }

protected:
    std::string name;
    int age;
};

// --- 派生类 (Derived Class) ---
// Student 公有继承自 Person
// 语法： class 派生类名 : 继承方式 基类名
class Student : public Person {
public:
    Student(const std::string& name, int age, int studentID) : Person(name, age), studentID(studentID) {}
    // Student 类特有的成员变量
    int studentID;

    // Student 类特有的成员函数
    void study() {
        // 可以直接访问从 Person 继承来的 public 成员 name
        std::cout << name << " is studying." << std::endl;
    }

    void sayHello() override {
        std::cout << "Hello, I am a student, my name is " << name << "I am " << age << " years old."<< std::endl;
    }

    ~Student() {
        std::cout << "Student " << name << " is destroyed." << std::endl;
    }
};

// --- 派生类 Teacher ---
class Teacher : public Person{
    public:
    Teacher(const std::string& name, int age, const std::string& subject) : Person(name, age), subject(subject) {}

    //特有的成员变量，教授的科目
    std::string subject;

    //特有的成员函数
    void teach() {
        std::cout << name << " is teaching " << subject << "." << std::endl;
    }

    void sayHello() override {
        std::cout << "Hello, I am a teacher, my name is " << name << ", I teach " << subject << "." << std::endl;
    }

    ~Teacher() {
        std::cout << "Teacher " << name << " is destroyed." << std::endl;
    }
};

int main() {
    // 错误尝试（抽象基类无法实例化）
    // Person p("Generic Person", 99);

    // 创建一个 Student 对象
    // Student student1("Li Ming", 18, 1002);
    // Teacher teacher1("Zhang San", 31, "C++");

    Person* p1 = new Student("Li Ming", 18, 1002);
    Person* p2 = new Teacher("Zhang San", 31, "C++");

    // --- 访问继承来的成员 ---
    // 调用从 Person 继承来的方法
    p1->sayHello(); // 输出: Hello, my name is Li Ming and I am 18 years old.
    // 调用 Student 特有的方法
    //student1.study(); // 输出: Li Ming is studying.

    // 调用从Person继承来的方法
    p2->sayHello(); // 输出: Hello, my name is Zhang San and I am 30 years old.
    //teacher1.teach(); // 输出: Zhang San is teaching C++.

    delete p1;
    delete p2;

    return 0;
}
