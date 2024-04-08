#include <iostream>
#include "add.cpp"
#include "mul.cpp"
int main(){
	int x, y;
	std::cin >> x;
	std::cin >> y;
	std::cout << "sum of " << x << " and " << y << " = " <<  add(x,y) << std::endl;
	std::cout << "multiple of " << x << " and " << y << " = " << mul(x,y) << std::endl;
}
