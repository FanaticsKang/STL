#include "my_process.h"

#include <sys/time.h>

#include <iostream>

MyProcess::MyProcess() {}

MyProcess::~MyProcess() {
  shutdown_ = true;
  if (thread_.joinable()) {
    thread_.join();
  }
}

void MyProcess::CallbackA(const object& obj) {
  cnt_a_++;
  LOG(INFO) << "recv ch-a " << obj.ShortDebugString();
}

void MyProcess::CallbackB(const object& obj) {
  cnt_b_++;
  LOG(INFO) << "recv ch-b " << obj.ShortDebugString();
}

void MyProcess::ThreadFunc() {
  while (!shutdown_) {
    LOG(INFO) << "cnt_a: " << cnt_a_ << ", cnt_b: " << cnt_b_;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}

void MyProcess::Init() {
  shutdown_ = false;
  cnt_a_ = 0;
  cnt_b_ = 0;
  thread_ = std::thread(&MyProcess::ThreadFunc, this);
  LOG(INFO) << "MyProcess Init OK";
}


void CallbackX(const object &obj) {
  LOG(INFO) << "recv " << obj.ShortDebugString();
}

