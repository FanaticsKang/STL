#include <iostream>
#include <map>
#include <string>
#include <tuple>

int main() {
  std::map<int, std::string> m;

  m.emplace(std::piecewise_construct, std::forward_as_tuple(10),
            std::forward_as_tuple(2, 48));
  std::cout << "m[10] = " << m[10] << '\n';

  // 下面是错误：它产生保有二个悬垂引用的 std::tuple<int&&, char&&>
  //
  // auto t = std::forward_as_tuple(20, 'a');
  // m.emplace(std::piecewise_construct, std::forward_as_tuple(10), t);
}