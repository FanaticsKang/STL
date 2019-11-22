#include <iostream>
#include <memory>

class MyClass {
public:
  MyClass(){
    std::cout << "默认构造函数" << std::endl;
  }
  MyClass(const MyClass&){
    std::cout << "复制构造函数" << std::endl;
  }
  MyClass& operator =(const MyClass&){
    std::cout << "赋值构造函数" << std::endl;
  }
};
void function(MyClass* test){

}
int main() {
  std::shared_ptr<MyClass> A = std::make_shared<MyClass>();
  MyClass* C = new MyClass();
  std::shared_ptr<MyClass> B = std::make_shared<MyClass>(*A);
  std::cout << "A: " << A << std::endl; 
  std::cout << "B: " << B << std::endl; 
  B = std::make_shared<MyClass>(*A.get());
  std::cout << "B: " << B << std::endl; 
  *B = MyClass(*A);
  std::cout << "B: " << B << std::endl; 
  function(A.get());
}