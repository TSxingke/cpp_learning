#include <iostream>
#include <memory> // 必须包含这个头文件

// 一个简单的类，用来观察构造和析构
class Entity {
public:
    Entity() { std::cout << "Entity created!" << std::endl; }
    ~Entity() { std::cout << "Entity destroyed!" << std::endl; }
    void Greet() { std::cout << "Hello from Entity!" << std::endl; }
};

int main() {
    // --- 1. std::unique_ptr ---
    std::cout << "--- Entering unique_ptr scope ---" << std::endl;
    {
        // 使用 std::make_unique 创建和初始化 (C++14+)
        // 这是推荐的方式，比直接用 new 更安全
        
        // 在这里，std::unique_ptr<Entity> 中的 <Entity> 是模板参数列表，表示unique_ptr管理的对象类型是 Entity。
        // C++中的模板（template）是泛型编程的一种方式，允许一个类或函数适用于不同的数据类型。
        // 当你看到类似于 std::vector<int>、std::unique_ptr<Entity> 这样的用法，
        // 尖括号 < > 里面的内容就是告诉编译器模板要具体用于哪种类型。
        // 只有定义了为模板的类或函数，才会用到 < > 指定类型。如果不是模板类，就不需要用 < >。
        std::unique_ptr<Entity> p_unique = std::make_unique<Entity>();

        // 调用方法就像普通指针一样
        p_unique->Greet();

        // std::unique_ptr<Entity> p_copy = p_unique; // ERROR! 不允许复制

    } // p_unique 在这里离开作用域，它的析构函数被调用，
      // 从而自动 delete 它所管理的 Entity 对象
    std::cout << "--- Exited unique_ptr scope ---" << std::endl;


    // --- 2. std::shared_ptr ---
    std::cout << "\n--- Entering shared_ptr scope ---" << std::endl;
    std::shared_ptr<Entity> p_shared1 = nullptr;
    {
        // 使用 std::make_shared 创建
        std::shared_ptr<Entity> p_shared2 = std::make_shared<Entity>();
        
        // use_count() 可以查看当前的引用计数
        std::cout << "Shared count after creation: " << p_shared2.use_count() << std::endl; // 1

        // 共享所有权，p_shared1 也指向了同一个对象
        p_shared1 = p_shared2;
        std::cout << "Shared count after assignment: " << p_shared2.use_count() << std::endl; // 2
        
        p_shared1->Greet();

    } // p_shared2 在这里离开作用域，引用计数从 2 减为 1
      // Entity 对象还不会被销毁
    
    std::cout << "p_shared2 is out of scope. Current shared count: " << p_shared1.use_count() << std::endl; // 1
    std::cout << "--- Exiting shared_ptr scope ---" << std::endl;

    return 0; // main函数结束，p_shared1 离开作用域，引用计数从 1 减为 0
              // Entity 对象此时才被销毁
}
