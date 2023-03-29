#include <iostream>
#include <memory>
#include <thread>
#include <vector>

class DataTest {
 public:
  DataTest(const double& data) : data_(data) { test2.resize(10000000); }
  ~DataTest() { std::cout << "delete:  " << this << std::endl; }

  std::vector<long> test2;
  double data_;
};

void PublishData(const DataTest& out_data) {
  while (true) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "wake up" << std::endl;
    std::cout << "out data: " << &out_data << std::endl;
    std::cout << "data: " << out_data.data_ << std::endl;
  }
}

int main() {
  std::thread th;
  DataTest* m_ptr_test;
  {
    std::shared_ptr<DataTest> data_ptr = std::make_shared<DataTest>(5);
    // DataTest data_ptr(10);
    std::cout << "data_ptr: " << data_ptr.get() << std::endl;
    th = std::thread(PublishData, *data_ptr);
    // PublishData(*data_ptr);
    // ChangeData(data_ptr);
  }
  // m_ptr_test->data_ = 10;

  if (th.joinable()) {
    th.join();
  }
}