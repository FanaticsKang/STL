#include<iostream>
#include<algorithm>
#include<functional>
#include<list>
using namespace std;
int main()
{
    list<int> mVct;
    
    for(int i = 0; i < 100; i++)
    {
        mVct.emplace_back(i);
    }
    
//     std::for_each(std::begin(mVct), std::end(mVct), std::greater<int>());
    mVct.sort(std::greater<int>());
    std::for_each(mVct.begin(),mVct.end(), [](int & tmp){cout << tmp << endl;});
    
    
    
    return 0;
}
