#ifndef MY_PROCESS_H
#define MY_PROCESS_H

#include <glog/logging.h>

#include <boost/bind.hpp>
#include <thread>

#include "object.pb.h"  //引入接口文件

class MyProcess {
 public:
  MyProcess();
  ~MyProcess();
  void Init();

  void CallbackA(const object& obj);

  void CallbackB(const object& obj);

 private:
  void ThreadFunc();

  std::thread thread_;
  std::atomic_bool shutdown_;
  std::atomic_uint64_t cnt_a_;
  std::atomic_uint64_t cnt_b_;
};


void CallbackX(const object &obj);

#endif  // MY_PROCESS_H
