#include <iostream>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};

    // 1. 数组名作为指针
    int* p_numbers = numbers; // 不需要 & 符号，因为 numbers 本身就代表首元素地址

    std::cout << "Address of the first element (&numbers[0]): " << &numbers[0] << std::endl;
    std::cout << "Value of the array name (numbers):         " << numbers << std::endl;
    std::cout << "Value of the pointer (p_numbers):          " << p_numbers << std::endl;

    // 2. 使用指针访问数组元素
    std::cout << "\n--- Accessing elements using pointer ---" << std::endl;
    std::cout << "First element (*p_numbers): " << *p_numbers << std::endl;
    
    // 移动指针到下一个元素并访问
    p_numbers++; // 指针算术，移动到 numbers[1]
    std::cout << "Second element after p_numbers++ (*p_numbers): " << *p_numbers << std::endl;
    
    // 使用 *(pointer + offset) 的方式访问
    p_numbers = numbers; // 重置指针回到数组开头
    std::cout << "Third element (*(p_numbers + 2)): " << *(p_numbers + 2) << std::endl;

    // 3. 使用指针遍历数组
    std::cout << "\n--- Iterating through array using a pointer ---" << std::endl;
    for (int* p = numbers; p < numbers + 5; ++p) {
        std::cout << "Address: " << p << "  Value: " << *p << std::endl;
    }

    return 0;
}
