#include <map>
#include <algorithm>
#include <iostream>

int main(){
    std::map<int, int, std::less<int>> less_map;
    std::map<int, int, std::greater<int>> greater_map;

    const int N = 100;
    for(int i = 0; i < N; ++i){
      less_map.emplace(i ,i);
      greater_map.emplace(i ,i);
    }

    auto iter_less = less_map.begin();
    auto iter_greater = greater_map.begin();
    for(int i = 0;i < N; ++i){
      std::cout << "i: " << i 
                << ", less map: " << iter_less->first
                << ", greater map: " << iter_greater->first << std::endl;
      ++iter_less;
      ++iter_greater;
    }
}