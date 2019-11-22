#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <eigen3/Eigen/Core>

class TicToc
{
public:
    TicToc()
    {
        tic();
    }

    void tic()
    {
        start = std::chrono::system_clock::now();
    }

    double toc()
    {
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        return elapsed_seconds.count() * 1000;
    }

private:
    std::chrono::time_point<std::chrono::system_clock> start, end;
};

int main(){
  const int N = 900000;
  std::set<std::string> all_string;
  for(int i = 0; i < N; ++i){
    all_string.emplace(std::to_string(i));
  }

  TicToc tic;
  for(auto tmp:all_string){
    // std::cout << tmp << std::endl;
  }
  double time1 = tic.toc();
  tic.tic();

  for(const auto& tmp:all_string){
    // std::cout << tmp << std::endl;
  }
  double time2 = tic.toc();

  tic.tic();
  for(auto& tmp:all_string){
    // std::cout << tmp << std::endl;
  }
  double time3 = tic.toc();
  std::cout << "time 1: " << time1 << std::endl;
  std::cout << "time 2: " << time2 << std::endl;
  std::cout << "time 3: " << time3 << std::endl;
}