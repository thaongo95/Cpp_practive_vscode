#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>

class Baseclass{
    public:
        virtual void function1();
        void function2();
};

class Shape{

public:
    virtual void get_area(){
        std::cout << "Calculation the Shape Area" << std::endl;
    }
};

#endif