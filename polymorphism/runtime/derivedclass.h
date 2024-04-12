#ifndef DERIVEDCLASS_H
#define DERIVEDCLASS_H
#include "baseclass.h"

class Derived_1:public Baseclass{
    public:
        void function1(){
            std::cout << "this is function1 of child 1" << std::endl;
        }
        void function2(){
            std::cout << "this is function2 of child 1" << std::endl;
        }
};
class Derived_2:public Baseclass{
    public:
        void function1(){
            std::cout << "this is function1 of child 2" << std::endl;
        }
        void function2(){
            std::cout << "this is function2 of child 2" << std::endl;
        }
};
class Derived_3:public Baseclass{
    public:
        void function1(){
            std::cout << "this is function1 of child 3" << std::endl;
        }
        void function2(){
            std::cout << "this is function2 of child 3" << std::endl;
        }
};
class Derived_4:public Baseclass{
    public:
        void function1(){
            std::cout << "this is function1 of child 4" << std::endl;
        }
        void function2(){
            std::cout << "this is function2 of child 4" << std::endl;
        }
};

class Rectangle: public Shape{
    int width, height;
public:
    Rectangle(int width, int height){
        this->width = width;
        this->height = height;
    }
    void get_area(){
        std::cout << "Area: " << width*height << std::endl;
    }
};

class Tritangle: public Shape{
    int bottom, height;
public:
    Tritangle(int bottom, int height){
        this->bottom = bottom;
        this->height = height;
    }
    void get_area(){
        std::cout << "Area: " << bottom*height/2 << std::endl;
    }
};

class Circle: public Shape{
    int R;
    const double Pi = 3.14;
public:
    Circle(int R){
        this->R = R;
    }
    void get_area(){
        std::cout << "Area: " << R*R*Pi << std::endl;
    }
};
#endif