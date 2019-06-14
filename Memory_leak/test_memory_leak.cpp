#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int main() {
  int *memory_leak = new int(1);
  std::cout << *memory_leak << std::endl;
}
