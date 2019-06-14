#include <experimental/filesystem>
#include <string>
#include <iostream>
namespace FS = std::experimental::filesystem;

int main(){
  std::string path = "/home/kang/";
  for (auto&fe : FS::directory_iterator(path))
	{
    std::cout << fe.path().filename() << std::endl;
  } 
}
