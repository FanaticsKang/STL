#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
int main() {
  std::list<int*> my_list;
  const int N = 100;
  for (int i = 0; i < N; ++i) {
    int* tmp = new int(i);
    my_list.push_back(tmp);
  }
  auto max_element = std::max_element(my_list.begin(), my_list.end(),
  [](const int* a, const int* b){
    return int(*a) < int(*b);
  });
  std::cout << **max_element << std::endl;
}