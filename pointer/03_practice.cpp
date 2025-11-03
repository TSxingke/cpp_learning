#include <iostream>

int* findMax(int* arr, int size){
    if (size <= 0){
        return nullptr;
    }
    else{
        int* max = arr;
        for (int* p = arr + 1; p < arr +size; p++){
            if (*p > *max){
                max = p;
            }
        }
        return max;
    }
}

int main(){
    int data[] = {1, 5, 2, 9, 3, 8};
    int size = sizeof(data) / sizeof(data[0]);

    int* max = findMax(data, size);
    if (max){
        std::cout << "The max value is: " << *max << std::endl;
        *max = *max - 1;
        for(int i=0; i<size; i++){
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    else{
        std::cout << "The array is empty." << std::endl;
    }
    return 0;
}