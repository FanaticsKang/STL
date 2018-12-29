#ifndef STACK_H_
#define STACK_H_

template<typename Type>
class Stack
{
private:
  enum{MAX = 10};
  Type items[MAX];
  int top;
  
public:
  Stack();
  bool isEmpty();
  bool isFull();
  bool Push(const Type &item);
  bool Pop(Type &item);
};

#endif //STACK_H_
