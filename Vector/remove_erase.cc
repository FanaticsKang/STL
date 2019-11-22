#include <iostream>
#include <vector>
#include <queue>

int main() {
  std::vector<int> test;
  const size_t max = 99;
  for (size_t i = 0; i < max; ++i) {
    test.emplace_back(i);
  }
  std::priority_queue<int, std::vector<int>, std::less<int>> test_p;
  for(auto tmp:test){
    test_p.push(tmp);
  }

  // for (auto iter = test.begin(); iter != test.end();) {
  //   if ((*iter) % 2 == 0) {
  //     std::cout << "before: " << *iter << ", " <<  (iter == test.end()) << ", " << test.capacity() << std::endl;
  //     iter = test.erase(iter);
  //     // std::cout << "after: "<< *iter << ", " <<  (iter == test.end()) << std::endl;
  //   } 
  //   else 
  //   {
  //     ++iter;
  //   }
  // }

  while(!test_p.empty()){
    std::cout << test_p.top() << std::endl;
    test_p.pop();
  }
}