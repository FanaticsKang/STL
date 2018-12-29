#include <iostream>
#include <string>

class StringFather{
public:
  std::string data;
};
class StringChild : public StringFather{
public:
  int i;
  double j,k,l,m,n;
};
void printMyString(const StringFather array[], int number)
{
  for(int i = 0; i < number; i++)
  {
    std::cout << array[i].data << std::endl;
  }
}
int main()
{
  StringChild testString[10];
  for(int i = 0; i < 10; ++i)
  {
    testString[i].data = std::to_string(i);
  }
  
  printMyString(testString, 10);
}


