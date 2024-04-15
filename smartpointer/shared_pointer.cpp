#include <iostream>
#include <memory>
#include <vector>
class Tensor{
    std::vector<std::vector<double>> matrix3D;
    public:
        void init(int num, int n){
            for (int j=0;j<n;j++){
                std::vector<double> temp;
                for (int i=0; i<n; i++){     
                    temp.push_back(num);
                }
                matrix3D.push_back(temp);
            }
        }
        void print(){
            for (int j=0;j<matrix3D.size();j++){
                for (int i=0; i<matrix3D.size(); i++){
                    std::cout << matrix3D[j][i] << " ";
                }
                std::cout << std::endl;
            }
        }
};

int main(){
    Tensor tensor1;
    tensor1.init(1, 5);
    tensor1.print();
    std::shared_ptr<Tensor> p1(new Tensor);  
    std::cout << p1.get() << std::endl;
    p1->init(0,10);
    p1->print();
    std::shared_ptr<Tensor> p2(p1);
    std::cout << p2.get() << std::endl;
    std::cout << p1.use_count() << std::endl;
    std::cout << p2.use_count() << std::endl;

    // p1.reset();
    // std::cout << p1.get() << std::endl;
    // std::cout << p2.get() << std::endl;
    // std::cout << p1.use_count() << std::endl;
    // std::cout << p2.use_count() << std::endl;
    
    std::shared_ptr<Tensor> p3 = std::make_shared<Tensor>(tensor1);
    p3->print();
    std::cout << p3.get() << std::endl;
    p3.swap(p2);
    p3->print();
    std::cout << p3.get() << std::endl;
    std::cout << p3.use_count() << std::endl;

    return 0;
}