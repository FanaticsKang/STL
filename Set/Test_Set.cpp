#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
  std::set<int> hello_set;
  for (int i = 0; i < 10; ++i) {
    hello_set.emplace(i);
  }
  hello_set.emplace(1);
  for (auto &iter : hello_set) {
    std::cout << iter << std::endl;
  }
}