#include <iostream>

int main(){
  int&& r_value= 42;
  int value = 50;
  // int&& r_value_2 = value;
  std::cout << "r_value: " << r_value << std::endl; 
}