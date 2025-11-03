#include <iostream>

int* createArray(int size, int initial_value){
    if (size <= 0){
        return nullptr;
    }
    else{
        int* arr = new int[size];
        for (int* p = arr; p < arr + size; p++){
            *p = initial_value;
        }
        return arr;
    }
}

int main(){
    int size;
    int initial_value;

    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    std::cout << "Enter the initial value: ";
    std::cin >> initial_value;

    int* arr = createArray(size, initial_value);
    if (arr){
        for (int* p = arr; p < arr + size; p++){
            std::cout << *p << " ";
        }
        std::cout << std::endl;
        delete[] arr;
        arr = nullptr;
    }
    else{
        std::cout << "Failed to create the array." << std::endl;
    }

    return 0;
}