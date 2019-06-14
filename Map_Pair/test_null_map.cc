#include <iostream>
#include <map>
#include <vector>
int main() {
  // std::map<int, int> test;
  // test.insert(std::pair<int, int>(0, 1));
  // test.insert(std::pair<int, int>(0, 2));
  // std::cout << test.size() << std::endl;
  int test_switch;
  for (int i = 0; i < 3; ++i) {
    std::cout << "i: " << i << std::endl;
    switch (i) {
      case (0): {
        std::cout << "0" << std::endl;        
      }break;
      case (1):
      case (2): {
        std::cout << "3" << std::endl;        
      }break;
      default:
        std::cout << "out" << std::endl;
    }
  }
}