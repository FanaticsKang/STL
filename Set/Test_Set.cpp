#include <algorithm>
#include <iostream>
#include <set>
#include <assert.h>
using namespace std;

int main() {
  // 设置为Release模式, assert不会生效.
  assert(false);
  std::set<int> hello_set;
  hello_set.erase(5);
  for (int i = 0; i < 10; ++i) {
    hello_set.emplace(i);
  }
  hello_set.emplace(1);  // not insert because it has
  for (auto &iter : hello_set) {
    std::cout << iter << std::endl;
  }
  hello_set.erase(5);
  hello_set.erase(50);// erase not exist
  for (auto &iter : hello_set) {
    std::cout << iter << std::endl;
  }
}
