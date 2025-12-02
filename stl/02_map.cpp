#include <iostream>
#include <map>
#include <string>

int main() {
    // 1. 创建一个 map，Key 是 string (名字)，Value 是 string (电话)
    std::map<std::string, std::string> phonebook;

    // 2. 插入数据
    // 方法一：使用下标 [] (最直观)
    phonebook["Alice"] = "123-4567";
    phonebook["Bob"] = "987-6543";
    
    // 方法二：使用 insert 和 pair
    phonebook.insert(std::make_pair("Charlie", "555-1234"));

    // 3. 修改数据
    phonebook["Alice"] = "111-1111"; // Key "Alice" 已存在，这会更新她的 Value

    // 4. 查找数据
    std::string searchName = "Bob";
    // find 方法返回一个迭代器
    auto it = phonebook.find(searchName);

    if (it != phonebook.end()) {
        // 找到了！
        // 迭代器指向一个 pair 对象
        // it->first 是 Key (名字)
        // it->second 是 Value (电话)
        std::cout << "Found " << it->first << ": " << it->second << std::endl;
    } else {
        std::cout << searchName << " not found." << std::endl;
    }

    // 5. 遍历 map
    std::cout << "\n--- Phonebook Directory ---" << std::endl;
    // map 中的元素类型是 std::pair<const Key, Value>
    // 使用 const auto& 是最高效的遍历方式
    for (const auto& entry : phonebook) {
        std::cout << entry.first << " -> " << entry.second << std::endl;
    }

    return 0;
}

