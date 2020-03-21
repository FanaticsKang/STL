#include <iostream>
#include <map>

int main() {
  std::multimap<double, double> state;
  for (double i = 0.0; i < 100; i += 0.5) {
    state.emplace(i, i);
  }
  double time = 2.3;
  auto iter_low = state.lower_bound(time);
  auto iter_up = state.upper_bound(time);
  if(iter_up == state.end()){
    std::cout << "Not Found" << std::endl;
    return -1;
  }
  std::cout << "find low: " << iter_low->first << std::endl;
  std::cout << "find up: " << iter_up->first << std::endl;
  --iter_low;
  --iter_up;
  std::cout << "find low -1: " << iter_low->first << std::endl;
  std::cout << "find up -1: " << iter_up->first << std::endl;
}