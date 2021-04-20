#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  std::vector<int> datas = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const int kValue = 4;
  auto iter_upper =
      std::upper_bound(datas.begin(), datas.end(), kValue,
                       [](const int m_threshold, const int value) {
                         std::cout << "upper value: " << value << ", "
                                   << (m_threshold < value) << std::endl;
                         return m_threshold < value;
                       });

  std::cout << "upper: " << *iter_upper << std::endl;
  auto iter_lower =
      std::lower_bound(datas.begin(), datas.end(), kValue,
                       [](const int value, const int m_threshold) {
                         std::cout << "lower value: " << value << ", "
                                   << (m_threshold > value) << std::endl;
                         return m_threshold > value;
                       });
  std::cout << "lower: " << *iter_lower << std::endl;
}