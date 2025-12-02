#include <iostream>
#include <vector>
#include <algorithm> // 包含 std::sort, std::for_each, std::count_if

int main() {
    // 初始化一个整型向量
    std::vector<int> numbers = {15, 3, 88, 10, 42, 7, 1};
    
    std::cout << "Original: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    // --- 任务 1: 排序 ---
    // 请使用 std::sort 和一个 lambda 表达式将 numbers 从大到小（降序）排序
    // 提示：Lambda 接收两个 int 参数 (int a, int b)，如果 a > b 返回 true
    // std::sort(numbers.begin(), numbers.end(), ... );
    std::sort(numbers.begin(), numbers.end(), [](int a, int b){return a > b;});

    std::cout << "Sorted (Desc): ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;


    // --- 任务 2: 计数 (捕获外部变量) ---
    int threshold = 20;
    // 请使用 std::count_if 和一个 lambda 表达式统计有多少个数字大于 threshold
    // 提示：Lambda 接收一个 int 参数 (int n)，需要捕获外部的 threshold，判断 n > threshold
    // int count = std::count_if(numbers.begin(), numbers.end(), ... );
    int count = std::count_if(numbers.begin(), numbers.end(), [threshold](int n){return n > threshold;});

    std::cout << "Count > " << threshold << ": " << count << std::endl; 


    // --- 任务 3: 修改 (引用参数 + 捕获) ---
    int bonus = 5;
    // 请使用 std::for_each 和一个 lambda 表达式，给每个数字加上 bonus
    // 提示：
    // 1. Lambda 的参数必须是引用 (int& n)，这样才能修改向量里的原始数值
    // 2. 你需要捕获 bonus
    // std::for_each(numbers.begin(), numbers.end(), ... );
    std::for_each(numbers.begin(), numbers.end(), [bonus](int& n){n += bonus;});

    std::cout << "After adding bonus " << bonus << ": ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}

