#include <iostream>

int main(){
    double array[] = {3.14, 2.71, 1.61, 9.8, 1.41};
    double* p = array + 4;

    for (;p >= array; p--){
        std::cout << "value is : " << *p << std::endl;
    }

    return 0;
}