#include <iostream>

template <class T>
class Box{
    private:
        T item;
    public:
        Box(T i) : item(i){}
        
        void setItem(T newItem){
            item = newItem;
        }

        T getItem() const{
            return item;
        }

        void display(){
            std::cout << "Item: " << item << std::endl;
        }
};

int main(){
    Box<int> intBox(10);
    Box<std::string> stringBox("Hello");

    int box1;
    std::string box2;
    box1 = intBox.getItem();
    box2 = stringBox.getItem();

    intBox.display();
    stringBox.display();

    return 0;
}