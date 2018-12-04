#include<iostream>
#include<iomanip>
#include<vector>

int main()
{
    std::vector<int> data {1,2,3};
    std::vector<int> back_data{4,5,6,7};
    
    std::copy(back_data.begin(), back_data.end(), std::back_inserter(data));
     
    for(auto tmp:data)
        std::cout << tmp << std::setw(2);
    std::cout << std::endl;
}
