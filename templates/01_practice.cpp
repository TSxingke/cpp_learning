#include <iostream>

template <class T>
void printArray(T* arr, int size){
    for(int i=0; i<size; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << "\n" << std::endl;
}

int main(){
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};

    printArray(intArray, 5);
    printArray(doubleArray, 5);
    printArray(charArray, 5);

    return 0;
}