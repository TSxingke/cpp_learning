#include <iostream>
#include <list>
#include <algorithm>

void printlist(const std::list<std::string>& lst){
    for(std::string n : lst){
        std::cout << n << " -> ";
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    std::list<std::string> mylist = {"Apple", "Banana", "Cherry"};

    auto it = mylist.begin();
    it++;
    mylist.insert(it, "Blueberry");

    it++;
    mylist.insert(it, "Blackberry");

    printlist(mylist);

    mylist.remove_if([](const std::string s){return s[0] == 'B';});

    std::cout << "After removing 'B': ";
    printlist(mylist);

    return 0;
}