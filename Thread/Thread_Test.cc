#include <iostream>
#include <thread>
#include <unistd.h>

void Run(int* num) {
  for(int i = 0; i < 100; ++i){
    std::cout << "num: " << *num << std::endl;
    sleep(1);    
  }
}

int main() {
  int printNum = 0;
  std::thread st(Run, &printNum);
  sleep(1);
  for(int j = 0; j < 10; ++j){
    ++printNum;
    // std::cout << "printNum: " << printNum << std::endl;
    sleep(5);
  }
  st.join();

}