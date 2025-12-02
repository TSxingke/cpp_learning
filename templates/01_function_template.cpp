#include <iostream>
#include <string>

// 定义一个函数模板 'generic_swap'
// T 是一个占位符，可以是任何数据类型
template <typename T>
void generic_swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// 定义一个函数模板 'generic_max'
template <typename T>
T generic_max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // --- 1. 使用 int 类型实例化模板 ---
    int int_a = 5, int_b = 10;
    std::cout << "Original ints: a = " << int_a << ", b = " << int_b << std::endl;
    generic_swap(int_a, int_b);
    std::cout << "Swapped ints:  a = " << int_a << ", b = " << int_b << std::endl;
    std::cout << "Max int is: " << generic_max(int_a, int_b) << std::endl;

    std::cout << "--------------------------" << std::endl;

    // --- 2. 使用 double 类型实例化模板 ---
    double double_a = 3.14, double_b = 2.71;
    std::cout << "Original doubles: a = " << double_a << ", b = " << double_b << std::endl;
    generic_swap(double_a, double_b);
    std::cout << "Swapped doubles:  a = " << double_a << ", b = " << double_b << std::endl;
    std::cout << "Max double is: " << generic_max(double_a, double_b) << std::endl;
    
    std::cout << "--------------------------" << std::endl;

    // --- 3. 使用 std::string 类型实例化模板 ---
    std::string str_a = "Hello", str_b = "World";
    std::cout << "Original strings: a = " << str_a << ", b = " << str_b << std::endl;
    generic_swap(str_a, str_b);
    std::cout << "Swapped strings:  a = " << str_a << ", b = " << str_b << std::endl;
    std::cout << "Max string is: " << generic_max(str_a, str_b) << std::endl; // 字符串比较是按字典序

    return 0;
}
