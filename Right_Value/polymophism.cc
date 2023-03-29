#include <iostream>

class Father {
 public:
  virtual void Call() { std::cout << "This is Father." << std::endl; }
};

class Son : public Father {
 public:
  void Call() override { std::cout << "This is Son." << std::endl; }
  void Call2() {
    Father::Call();
    Call();
  }
};

int main() {
  Son son;
  son.Call2();
}