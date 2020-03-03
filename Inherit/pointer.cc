#include <iostream>

class TimeKeeper{
public:
  int father_index;
  TimeKeeper* GetTimeKeeper(){
    return this;
  }
};

class AtomicClock: public TimeKeeper{
public:
  int index = 1;
};

int main(){
  AtomicClock* ac = new AtomicClock();
  TimeKeeper* tk = ac->GetTimeKeeper();
  std::cout << "Get Here" << std::endl;
  delete tk;
  std::cout << "Get Here 2" << std::endl;
  std::cout << "index: " <<ac->index << std::endl;
  std::cout << "father index: " <<ac->father_index<< std::endl;
}