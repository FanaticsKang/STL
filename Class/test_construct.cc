#include "iostream"
#include "string"
void function(std::string* const str_ptr){
  std::cout << *str_ptr << std::endl;
}

int main(){
  std::string mystring();
  // function(&mystring); //Error
}