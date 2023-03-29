#include <atomic>
#include <memory>
#include <iostream>

class A {
 public:
  double test_;
};

int main() {
  std::atomic<A *> my_a;
  my_a = new A();
  my_a.load()->test_ = 10;

  std::shared_ptr<std::atomic<A>> my_b;
  my_b = std::make_shared<std::atomic<A>>();
}