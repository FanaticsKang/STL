#include <iostream>
struct Point{
  double x = 10;
  double y = 0;
  double z = 5;
};

int main(){
  Point a = {1.0, 1.0, 1.0};
  // Point b(1.0, 1.0, 1.0);
  Point c{1.0, 2.0, 3.0};
  Point d;

  std::cout << "c.x: " << c.x << std::endl;
  std::cout << "c.y: " << c.y << std::endl;
  std::cout << "c.z: " << c.z << std::endl;

  std::cout << "d.x: " << d.x << std::endl;
  std::cout << "d.y: " << d.y << std::endl;
  std::cout << "d.z: " << d.z << std::endl;

}
