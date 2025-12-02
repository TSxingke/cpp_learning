#include <iostream>
#include <list>
#include <algorithm>

void printList(const std::list<int>& lst) {
    // list 不支持下标 [] 访问，必须使用迭代器遍历
    // 这里的 n 就是通过迭代器解引用得到的值
    for (int n : lst) {
        std::cout << n << " -> ";
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    // 1. 创建一个 list
    std::list<int> myList = {10, 20, 30};
    std::cout << "Initial list: ";
    printList(myList);

    // 2. 头部和尾部插入 (vector 没有 push_front，因为效率极低)
    myList.push_back(40);  // 尾部插入
    myList.push_front(5);  // 头部插入！list 的强项
    
    std::cout << "After push_back(40) and push_front(5): ";
    printList(myList);

    // 3. 在中间插入
    // 首先需要找到插入位置的迭代器
    auto it = myList.begin(); 
    it++; // 移动迭代器到第二个位置 (指向 10)
    it++; // 移动到第三个位置 (指向 20)
    
    // 在 20 之前插入 15
    myList.insert(it, 15);
    std::cout << "After inserting 15 before 20: ";
    printList(myList);

    // 4. 删除特定值的元素
    // list 自带 remove 方法，非常方便
    myList.remove(10); // 删除所有的 10
    std::cout << "After removing 10: ";
    printList(myList);

    // 5. 排序 (注意：list 有自己的 sort 成员函数)
    // std::sort(myList.begin(), myList.end()); // 错误！std::sort 需要随机访问迭代器，list 不支持
    myList.sort(); // 正确：使用 list 自带的高效排序
    std::cout << "Sorted list: ";
    printList(myList);

    return 0;
}



