#include <unistd.h>
#include <iostream>
#include <thread>

void Run(int* num) {
  for (int i = 0; i < 100; ++i) {
    std::cout << "num: " << *num << std::endl;
    sleep(1);
  }
}

class MyThread {
 public:
  void Run() {
    int printNum = 0;
    // this = &thread0
    std::thread th(&MyThread::Print, this, &printNum);
    for (int j = 0; j < 10; ++j) {
      ++printNum;
      // std::cout << "printNum: " << printNum << std::endl;
      sleep(5);
    }
    th.join();
  };
  void Print(int* num) {
    for (int i = 0; i < 100; ++i) {
      std::cout << "num: " << *num << std::endl;
      sleep(2);
    }
  }
};

int main() {
  MyThread thread0;
  thread0.Run();
}