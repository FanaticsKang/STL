#include<iostream>
#include<algorithm>
#include<array>

using namespace std;

int main()
{
    std::array<int, 100> test_array;
    int i = 0;
    std::generate(test_array.begin(), test_array.end(),
                  [i]()mutable{return i++;}
    );
    
    std::for_each(test_array.begin(), test_array.end(),
                  [](int& output){cout << output << endl;});
}
