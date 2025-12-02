#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

int main(){
    std::vector<std::string> fruits = {"apple", "banana", "apple", "orange", "banana", "apple", "orange", "apple", "banana", "apple"};
    std::map<std::string, int> fruit_count;

    for(const auto& fruit : fruits){
        fruit_count[fruit]++;
    }

    for(const auto& entry : fruit_count){
        std::cout << entry.first << " : " << entry.second << std::endl;
    }

    return 0;
}