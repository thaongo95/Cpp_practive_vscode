#include <iostream>


/*
   Smart Pointer is a wrapper class over a pointer with an operator like * and -> overload
   the object of the smart pointer class look lik normal pointer
   but it can dealllocate and free destroyed object memory.
    https://www.geeksforgeeks.org/smart-pointers-cpp/
*/
template<typename T>
class Smart_Pointer{
    T *ptr;
public:
    explicit Smart_Pointer(T* p = NULL){
        ptr = p;
    }
    ~Smart_Pointer(){
        std::cout << "delete pointer" << std::endl;
        delete(ptr);
    }
    T& operator*(){
        return *ptr;
    }
    T* operator->(){
        return ptr;
    }
};
class A{
    int a{10};
    char b{'*'};
    public:
        void print(){
            for (int i=0;i<a;i++)
                std::cout << b;
            std::cout << std::endl;
    }
};
int main(){
    for (int i=0; i<1000; i++){
        Smart_Pointer<A> p1(new A);
        p1->print();
    }
    
    // std::cout << *p1 << std::endl;
}