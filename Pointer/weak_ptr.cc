// std::weak_ptr 用来解决循环引用的问题
// 解决的方法: 把A和B其中的任一个ptr改成weak_ptr即可，不在于个数

#include <iostream>
#include <memory>

class B;
class A {
 public:
  A() { std::cout << "A" << std::endl; }
  ~A() { std::cout << "~A" << std::endl; }

 public:
  std::shared_ptr<B> ptr;
};

class B {
 public:
  B() { std::cout << "B" << std::endl; }
  ~B() { std::cout << "~B" << std::endl; }

 public:
  std::shared_ptr<A> ptr1;
  std::shared_ptr<A> ptr2;
  // std::weak_ptr<A> ptr1;
  // std::weak_ptr<A> ptr2;
};

void fun() {
  std::shared_ptr<A> pa = std::make_shared<A>();
  std::shared_ptr<B> pb = std::make_shared<B>();
  pa->ptr = pb;
  pb->ptr1 = pa;
  pb->ptr2 = pa;
}

int main() {
  fun();
  return 0;
}
