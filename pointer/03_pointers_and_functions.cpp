#include <iostream>

// --- Example 1: Modifying arguments using pointers ---
// 这个函数接收两个指向int的指针作为参数
void swap(int* a, int* b) {
    std::cout << "\nInside swap function:" << std::endl;
    std::cout << "Address of a: " << a << ", Address of b: " << b << std::endl;
    
    int temp = *a; // temp = a指向的值
    *a = *b;       // a指向的值 = b指向的值
    *b = temp;       // b指向的值 = temp
    
    std::cout << "Swapped values inside function: *a = " << *a << ", *b = " << *b << std::endl;
}

// --- Example 2: Passing arrays to functions efficiently ---
// 当数组名作为参数传递时，实际上传递的是指向首元素的指针
// 因此 double arr[] 和 double* arr 是完全等价的
double sumArray(const double* arr, int size) {
    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        // arr[i] is equivalent to *(arr + i)
        total += arr[i];
    }
    return total;
}


int main() {
    // --- Test for Example 1 ---
    int x = 10;
    int y = 20;
    std::cout << "--- Testing swap() ---" << std::endl;
    std::cout << "Original values: x = " << x << ", y = " << y << std::endl;
    std::cout << "Address of x: " << &x << ", Address of y: " << &y << std::endl;
    
    // 我们传递的是变量的地址
    swap(&x, &y);
    
    std::cout << "\nAfter swap function call:" << std::endl;
    std::cout << "Final values: x = " << x << ", y = " << y << std::endl;

    // --- Test for Example 2 ---
    double my_doubles[] = {1.5, 2.5, 3.5, 4.5};
    double result = sumArray(my_doubles, 4); // my_doubles 就是首元素地址
    std::cout << "\n--- Testing sumArray() ---" << std::endl;
    std::cout << "Sum of the array is: " << result << std::endl;

    return 0;
}
