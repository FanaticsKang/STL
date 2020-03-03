#include <iostream>

class A {
 public:
  A(int i) : number(i) {}
  int number;
};

class B{
  public:
  explicit B(const A& a):number(a.number){}
  int number;
};

void show(const A& a) { std::cout << a.number << std::endl; }

int main() {
  A a(1);
  B b(2);
  show(a);

}
