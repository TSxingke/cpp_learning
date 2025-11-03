#include <iostream>
#include <memory>

// 函数返回一个管理数组的 unique_ptr
std::unique_ptr<int[]> createArray(int size, int initial_value) {
    if (size <= 0) {
        return nullptr;
    }
    
    // 创建 unique_ptr 来管理动态数组
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(size);
    
    // 使用下标来填充数组，这是最直接和清晰的方式
    for (int i = 0; i < size; i++) {
        arr[i] = initial_value;
    }
    
    // 返回 unique_ptr，所有权被转移给调用者
    return arr;
}

int main() {
    int size;
    int initial_value;

    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    std::cout << "Enter the initial value: ";
    std::cin >> initial_value;

    // 接收函数返回的 unique_ptr
    std::unique_ptr<int[]> arr = createArray(size, initial_value);
    
    if (arr) { // 检查 unique_ptr 是否为空
        // 使用 .get() 方法获取原始指针来进行遍历
        int* p_raw = arr.get(); 
        for (int i = 0; i < size; i++) {
            // 也可以直接用 arr[i]，这里为了演示 .get() 的用法
            std::cout << p_raw[i] << " "; 
        }
        std::cout << std::endl;
        
        // 最重要的一点：不需要写 delete[] arr; 
        // 当 arr 离开作用域时，内存会自动释放
    }
    else {
        std::cout << "Failed to create the array." << std::endl;
    }

    return 0;
}