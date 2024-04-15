#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>

class Employee{
    std::string name;
    int salary;
    public:
        virtual void raise_salary(double amount){
            std::cout << "Raise salary for everyone" << std::endl;
        };
        virtual int get_salary(){
            std::cout << "Get salary of employee" << std::endl;
        }
};

class Manager: public Employee{
    int base_salary{3000};
    public:
        void raise_salary(double amount){
            base_salary *= (1+amount);
        }
        int get_salary(){
            return base_salary;
        }
};
class Engineer: public Employee{
    int base_salary{2000};
    public:
        void raise_salary(double amount){
            base_salary *= (1+ amount);
        }
        int get_salary(){
            return base_salary;
        }
};
class Programmer: public Employee{
    int base_salary{2200};
    public:
        void raise_salary(double amount){
            base_salary *= (1+amount);
        }
        int get_salary(){
            return base_salary;
        }
};

#endif