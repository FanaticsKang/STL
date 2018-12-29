#include <iostream>
#include <memory>
#include <string>

using namespace std;

class myInt {
  int value = 0;

public:
  myInt(){};
  myInt(int i) : value(i){};
  ~myInt() { cout << "One Class Quit" << endl; };
  friend myInt &operator+(int plus, myInt &input) {
    input.value += plus;
    return input;
  }
  myInt &operator+(int plus) {
    value += plus;
    return *this;
  }

  friend void show_out_data(myInt &input) { cout << input.value << endl; }

  void show_myInt() { cout << value << endl; }

public:
  static int index;
};

void show_myInt(myInt input, int times) {
  for (int i = 0; i < times; i++) {
    input.show_myInt();
  }
}

int main(int argc, char **argv) {

  myInt i;
  myInt j;
  j = 1; // destory old j, and create a tmpOne, Copy to j
  show_out_data(j);
  show_myInt(5, 2);
  // destory tmpOne and j
}
