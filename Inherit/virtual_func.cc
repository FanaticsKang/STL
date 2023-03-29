#include <iostream>
#include <memory>
#include <vector>
template <typename T>
class Queue {
  Queue(const size_t _size) : kSize(_size) { data_.resize(_size, nullptr); }

  bool Push(const T &value) {
    if(data_[index_] != nullptr){
      return false;
    }
    data_[index_] = std::make_shared<T>(value);
    ++index_;
    index_ %= kSize;
    return true;
  }

  bool Pop(const T *const output) {
    for (int i = 0; i < kSize; ++i) {
      int j = index_ + i;
      j %= kSize;
      if (data_[j] == nullptr) {
        continue;
      }
      *output = *data_[j];
      data_[j] = nullptr;
      return true;
    }
    return false;
  }

 private:
  const size_t kSize;
  int index_ = 0;
  std::vector<std::shared_ptr<T>> data_;
};