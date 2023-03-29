#include <iostream>
#include <mutex>
#include <thread>
#include "absl/memory/memory.h"
#include "absl/synchronization/mutex.h"

class TestMutex {
 public:
  void SetData(const double data) {
    // std::lock_guard<std::mutex> lock_guard(mutex_);
    // absl::MutexLock locker(&mutex_);
    protected_data_ = data;
  }

  double GetData() {
    // std::lock_guard<std::mutex> lock_guard(mutex_);
    // absl::MutexLock locker(&mutex_);
    return protected_data_;
  }

 private:
  absl::Mutex mutex_;
  // no difference
  double protected_data_ GUARDED_BY(mutex_);
};

void PrintData(TestMutex *const input) {
  while (true) {
    std::cout << input->GetData() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
}

int main() {
  TestMutex test;
  double data = 0.0;
  test.SetData(data);
  std::thread th(PrintData, &test);

  while (true) {
    data += 1.0;
    test.SetData(data);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}