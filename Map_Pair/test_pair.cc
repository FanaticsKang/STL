#include <iostream>
#include <utility>
#include <vector>
#include <memory>

void getReferencePointer(int &input)
{
  int *ptr = &input;
}
int main()
{
  std::vector<std::pair<double, std::shared_ptr<int>>> data;
  data.resize(10);
  
  int i = 0;
  for(auto &one:data)
  {
    std::cout << "data[" << i++ << "]: " << one.first;
    if(one.second == nullptr)
    {
      std::cout << ", the second is nullptr";
    }
    std::cout << std::endl;
    
  }
}
