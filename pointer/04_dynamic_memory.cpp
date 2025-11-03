#include <iostream>

int main() {
    // --- 1. 动态分配单个变量 ---
    int* p_int = new int; // 在堆上分配一个int大小的内存
    *p_int = 123;         // 通过指针为这块内存赋值

    std::cout << "--- Dynamic single variable ---" << std::endl;
    std::cout << "Address: " << p_int << std::endl;
    std::cout << "Value: " << *p_int << std::endl;

    // 释放内存
    delete p_int;
    p_int = nullptr; // 好习惯：释放后将指针置为空，防止“悬垂指针”

    // --- 2. 动态分配数组 ---
    int size;
    std::cout << "\n--- Dynamic array ---" << std::endl;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // 数组的大小可以在运行时决定
    int* p_array = new int[size];

    // 为数组填充值
    for (int i = 0; i < size; ++i) {
        p_array[i] = (i + 1) * 10;
    }

    // 打印数组内容
    std::cout << "Array contents: ";
    for (int i = 0; i < size; ++i) {
        std::cout << p_array[i] << " ";
    }
    std::cout << std::endl;

    // 释放数组内存
    delete[] p_array;
    p_array = nullptr;

    return 0;
}
