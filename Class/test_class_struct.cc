#include <iostream>
#include <string>

using namespace std;

struct Point3d
{
  double x;
  double y;
  string z;
};

class Father
{
public:
  double x;
  double y;
  string z;
  
  Father(double in_x, double in_y, string in_z):x(in_x), y(in_y), z(in_z){};
  
  virtual void Show()
  {
    cout << "This is FATHER Show." << endl;
    PrivateShow();
  };
  
private:
  void PrivateShow()
  {
    cout << "This is father Private show." <<endl;
  };
};

class Child:public Father
{
public:
  Child(double in_x, double in_y, string in_z):Father(in_x, in_y, in_z){};
  void Show ()
  {
    cout << "This is child Show" << endl;
    //Father::Show();
  }
};

int main()
{
  Point3d my_point{1,2,"3"};
  
  Child myData{1,2,"3"};
  Father &myFather = myData;
  Father *myFather2 = new Child(1,2,"3");
  //myFather.Show();
  myFather2->Show();
  delete myFather2;
}
