#include <functional>
#include <iostream>
#include <vector>
#include "core.h"
class Component {
 public:
  void Function(const int i, const int j) {
    std::cout << "This is a function: " << i << " / " << j << std::endl;
  }

 public:
  Core m_core;
};

int main() {
  Component com;
  com.m_core.func_ = std::bind(&Component::Function, &com,
                               std::placeholders::_1, std::placeholders::_2);
  com.m_core.func_(2, 10);
}