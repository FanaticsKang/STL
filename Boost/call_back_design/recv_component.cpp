#include "recv_component.h"

#include <sys/time.h>

#include <iostream>

#include "object.pb.h"  //引入接口文件

ReceiveComponent::ReceiveComponent() : AbstractComponent("recv") {}

ReceiveComponent::~ReceiveComponent() {
  shutdown_ = true;
  for (std::thread &th : threads_for_callback_) {
    if (th.joinable()) {
      th.join();
    }
  }
}

static double getNowTime() {
  struct timeval tv = {0};
  struct timezone tz = {0};
  const int result = gettimeofday(&tv, &tz);
  if (result != 0) {
    return 0.0;
  }
  return double(tv.tv_sec) + double(tv.tv_usec) / 1000000.0;
}

void ReceiveComponent::step() {
  //接收数据
  double timestamp;
  MetaData mdata = getDataNew("ch-0", &timestamp);  // ch-0 字符串与发送段一致

  //反序列化
  object obj;
  obj.ParseFromString(mdata);

  //打印相关信息
  LOG(INFO) << "recv ch-0 " << obj.ShortDebugString() << ", t: " << timestamp
            << ", dt: " << getNowTime() - timestamp;
}

void ReceiveComponent::init() {
  my_process_.Init();
  shutdown_ = false;

  // 创建两个线程，对应相应的回调函数
  // 外部函数
  Subscribe("ch-a", CallbackX);
  // 成员函数
  Subscribe("ch-b", &MyProcess::CallbackB, &my_process_);
}
