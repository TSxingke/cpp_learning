#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int a = 10;
    int b = 20;

    std::cout << "Outer variables: a = " << a << ", b = " << b << std::endl;

    // --- 1. 空捕获 [] ---
    // 只能使用参数 x, y，完全看不到外面的 a 和 b
    // 这种 Lambda 是最纯粹的，通常用于 sort 等算法
    auto add = [](int x, int y) {
        // return a + x; // 错误！编译失败，因为没捕获 a
        return x + y;
    };
    std::cout << "1. Empty capture result: " << add(5, 5) << std::endl;


    // --- 2. 按值捕获 [a] ---
    // 把外面的 a "拷贝" 一份带进来。
    // 在 Lambda 内部可以读取 a，但不能修改它（它是只读的），
    // 且 Lambda 里的 a 只是个副本，不会影响外面的 a。
    auto captureByValue = [a](int x) {
        std::cout << "   [Inside Lambda] captured a = " << a << std::endl;
        // a = 100; // 错误！默认情况下按值捕获是只读的
        return a + x;
    };
    std::cout << "2. Capture by value result: " << captureByValue(50) << std::endl;


    // --- 3. 按引用捕获 [&b] ---
    // 把外面的 b 的 "引用" 带进来。
    // 此时 Lambda 内部的 b 就是外面的 b，可以读取，也可以修改！
    auto captureByReference = [&b]() {
        std::cout << "   [Inside Lambda] captured b = " << b << std::endl;
        b = 999; // 修改了外面的 b！
        std::cout << "   [Inside Lambda] changed b to 999" << std::endl;
    };
    
    captureByReference(); // 执行 Lambda
    std::cout << "3. After capture by reference, outer b = " << b << std::endl;

    
    // --- 4. 混合捕获 [=] 和 [&] (高级) ---
    // [=] 表示：所有外部变量都按值捕获
    // [&] 表示：所有外部变量都按引用捕获
    int c = 30;
    auto captureAll = [=]() {
        std::cout << "4. Capture all by value: a=" << a << ", b=" << b << ", c=" << c << std::endl;
    };
    captureAll();

    return 0;
}

