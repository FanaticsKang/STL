#include<iostream>
using namespace std;
class Widget
{
public:
    Widget(){cout << "Void Function is called" <<endl;};
    Widget(int input, bool b):index(input), isNot(b){cout << "Bool Function is called" <<endl;};
    Widget(int input, double d):index(input), loc(d){cout << "Double Function is called" <<endl;};
    Widget(std::initializer_list<long double> il){cout << "Initializer_list Function is called" <<endl;};
public:
    int index = 0;
    bool isNot = false;
    double loc = 0.0;
};

int main()
{
    /*
    Widget w1();//function which return Widget
    Widget w2{};
    
    cout << w2.index << endl;
    //cout << w1.i << endl; //error
    */
    
    initializer_list<int> il = {1, 2, 3};
    Widget w1(10, true);
    Widget w2{10, true};
    
    
    for(auto& tmp:il)
    {
        cout << tmp << endl;
    }
    
    
}
