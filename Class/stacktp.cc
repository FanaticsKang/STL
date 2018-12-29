#include "stacktp.h"

template<typename Type>
Stack<Type>::Stack()
{
  top = 0;
}

template<typename Type>
bool Stack<Type>::isEmpty()
{
  return top == 0;
}

template<typename Type> 
bool Stack<Type>::isFull()
{
  return top == MAX;
}

template<typename Type>
bool Stack<Type>::Pop(Type& item)
{
  if(top > 0)
  {
    item = items[--top];
    return true;
  }
  return false;
}

template<typename Type> 
bool Stack<Type>::Push(const Type& item)
{
  if(top < MAX)
  {
    items[top++] = item;
    return true;
  }
  else
    return false;
}
