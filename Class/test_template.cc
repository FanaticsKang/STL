#include "stacktp.cc"
#include <string>
#include <iostream>
int main()
{
  Stack<std::string> st;
  st.Push("Hello1");
  std::string po;
  st.Pop(po);
  std::cout << po << std::endl;
}
