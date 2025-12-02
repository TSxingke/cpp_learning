# C++ 进阶学习之旅

本项目记录了从 C++ 继承多态到现代 C++ 特性的完整学习路径。包含丰富的示例代码、针对性的练习题，以及一个综合性的“学生信息管理系统”实战项目。

## 📂 目录结构与学习内容

### 1. 面向对象编程 (OOP) - 继承与多态
位于项目根目录，涵盖 OOP 核心三大特性：
- **基础继承**：`01_simple_inheritance.cpp` (基类与派生类)
- **访问权限**：`02_access_specifiers.cpp` (public / protected / private 的区别)
- **构造与析构**：`03_constructors_destructors.cpp` (调用顺序详解)
- **多态与虚函数**：`04_polymorphism.cpp` (virtual 关键字, override, 动态绑定)
- **虚析构函数**：`05_virtual_destructor.cpp` (多态基类的内存安全)
- **抽象基类**：`06_abstract_class.cpp` (纯虚函数与接口定义)

### 2. 指针与内存管理
位于 `pointer/` 目录，深入理解 C++ 的灵魂：
- **指针基础**：`01_what_is_a_pointer.cpp` (地址与解引用)
- **指针与数组**：`02_pointers_and_arrays.cpp` (指针算术)
- **指针与函数**：`03_pointers_and_functions.cpp` (传址调用)
- **动态内存**：`04_dynamic_memory.cpp` (`new` / `delete`, 堆内存管理)
- **智能指针**：`05_smart_pointers.cpp` (现代 C++ 的 RAII, `unique_ptr`, `shared_ptr`)

### 3. 泛型编程 - 模板
位于 `templates/` 目录，学习编写通用代码：
- **函数模板**：`01_function_template.cpp` (通用算法)
- **类模板**：`02_class_template.cpp` (通用数据结构)

### 4. 现代 C++ 特性 - Lambda 表达式
位于 `lambda/` 目录，掌握函数式编程风格：
- **捕获列表详解**：`01_lambda_capture.cpp` (`[]`, `[=]`, `[&]` 的区别)
- **实战练习**：`02_practice.cpp` (结合 `std::sort`, `std::for_each` 使用)

### 5. 标准模板库 (STL)
位于 `stl/` 目录，使用标准库的高级工具：
- **双向链表**：`01_list.cpp` (`std::list`, 头部插入与删除)
- **键值对映射**：`02_map.cpp` (`std::map`, 词频统计示例)

### 6. 🏆 综合实战 - 学生信息管理系统
位于 `student_management_system/` 目录。
这是一个基于命令行的完整管理系统，综合运用了上述所有知识点。

**主要功能：**
- **添加学生**：创建对象并存储到 `std::vector` 容器中。
- **显示列表**：遍历并打印学生信息。
- **持久化存储**：利用文件流 (`fstream`) 实现数据的保存与自动加载，防止数据丢失。
- **智能排序**：利用 Lambda 表达式和 `std::sort` 按学号对学生进行排序。

**核心代码结构：**
- `main.cpp`: 程序入口与用户交互菜单。
- `Student.h/cpp`: 学生类的定义与实现（封装数据）。
- `StudentManager.h/cpp`: 管理类的定义与实现（业务逻辑）。

## 🚀 如何编译运行

请确保已安装 C++ 编译器 (如 g++, clang++, 或 MSVC)。

**1. 运行单个练习文件**
例如，运行多态的示例：
```bash
g++ 04_polymorphism.cpp -o app
./app
```

**2. 运行学生管理系统**
需要同时编译所有相关的 `.cpp` 文件：
```bash
cd student_management_system
g++ main.cpp Student.cpp StudentManager.cpp -o sms
./sms
```

## 📝 学习心得
通过本项目的实践，主要掌握了：
1. **OOP 思想**：如何通过封装、继承和多态来构建清晰的代码结构。
2. **底层机制**：深入理解了指针操作、内存模型以及虚函数表的原理。
3. **现代 C++**：学会了使用智能指针管理资源，使用 Lambda 简化代码，以及使用 STL 提升开发效率。
4. **工程能力**：掌握了头文件与源文件分离的模块化开发方式，以及基本的文件 I/O 操作。

Happy Coding!

