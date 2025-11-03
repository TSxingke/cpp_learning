#include <iostream>

int main() {
    // 1. 声明一个普通变量
    int score = 95;
    double price = 19.99;
    char grade = 'A';
    
    // 2. 声明一个指向 int 类型的指针变量
    // int* 表示 "一个指向 int 的指针"
    int* p_score;
    double* p_price;
    char* p_grade;

    // 3. 使用 & 运算符获取 score 的地址，并存入指针 p_score
    p_score = &score;
    p_price = &price;
    p_grade = &grade;

    std::cout << "--- Addresses ---" << std::endl;
    std::cout << "Address of 'score' variable (&score): " << &score << std::endl;
    std::cout << "Value of 'p_score' pointer (p_score): " << p_score << std::endl;
    std::cout << "Address of 'p_score' pointer itself (&p_score): " << &p_score << std::endl;
    
    std::cout << "\n--- Values ---" << std::endl;
    std::cout << "Value of 'score' variable (score): " << score << std::endl;

    std::cout << "\n--- Addresses and Values of 'price' and 'grade' ---" << std::endl;
    std::cout << "Address of 'price' variable (&price): " << &price << " Value of 'price' variable (price): " << price << std::endl;
    // 打印字符串的地址，使用 static_cast<void*>(&grade) 将地址转换为 void* 类型才能正确显示其地址
    std::cout << "Address of 'grade' variable (&grade): " << static_cast<void*>(&grade) << " Value of 'grade' variable (grade): " << grade << std::endl;

    // 4. 使用 * 运算符解引用指针，获取指针指向地址上的值
    std::cout << "Value pointed to by 'p_score' (*p_score): " << *p_score << std::endl;

    // 5. 通过指针修改变量的值
    std::cout << "\n--- Modifying through pointer ---" << std::endl;
    *p_score = 100; // 解引用指针，然后赋值
    std::cout << "New value of 'score' after modification: " << score << std::endl;

    *p_price = 29.99;
    *p_grade = 'B';
    std::cout << "New value of 'price' after modification: " << price << std::endl;
    std::cout << "New value of 'grade' after modification: " << grade << std::endl;

    return 0;
}
