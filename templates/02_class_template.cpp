#include <iostream>
#include <string>

// 定义一个类模板 'Pair'
// 它可以存储两种不同类型的值，由 T1 和 T2 决定
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    // 构造函数
    Pair(T1 f, T2 s) : first(f), second(s) {}

    T1 getFirst() const {
        return first;
    }

    T2 getSecond() const {
        return second;
    }

    void setFirst(T1 value) {
        first = value;
    }

    void display() const {
        std::cout << "(" << first << ", " << second << ")" << std::endl;
    }
};

int main() {
    // 1. 实例化一个 Pair<int, double>
    Pair<int, double> p1(10, 3.14);
    std::cout << "Pair 1: ";
    p1.display();

    // 2. 实例化一个 Pair<std::string, int>
    Pair<std::string, int> p2("Age", 25);
    std::cout << "Pair 2: ";
    p2.display();
    std::cout << "The first element of p2 is: " << p2.getFirst() << std::endl;

    // 3. 实例化一个 Pair<char, char>
    Pair<char, char> p3('A', 'Z');
    std::cout << "Pair 3: ";
    p3.display();

    return 0;
}
