#ifndef RECV_COMPONENT_H
#define RECV_COMPONENT_H

#include <glog/logging.h>

#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <thread>

#include "capilot/abstract_component.h"
#include "capilot/component_factory.h"
#include "my_process.h"

class ReceiveComponent : public AbstractComponent {
 public:
  ReceiveComponent();
  ~ReceiveComponent();

 protected:
  virtual void step() override;
  virtual void init() override;

 private:
  // 普通函数对应的CallBack内部架构
  // 输入参数:
  // 1. topic 名称;
  // 2. 回调函数;
  template <class M>
  void Subscribe(const std::string& topic,
                 void (*callback_function)(const M&)) {
    threads_for_callback_.push_back(
        std::thread(&ReceiveComponent::ThreadForCallback<M>, this, topic,
                    callback_function));
    // LOG(INFO) << "subscribed topic: " << topic;
  }

  // 类成员函数对应的CallBack内部架构
  // 输入参数:
  // 1. topic 名称;
  // 2. 类的成员函数;
  // 3. 类
  template <class M, class T>
  void Subscribe(const std::string& topic,
                 void (T::*callback_function)(const M&), T* obj) {
    threads_for_callback_.push_back(
        std::thread(&ReceiveComponent::ThreadForCallback<M>, this, topic,
                    boost::bind(callback_function, obj, _1)));
    // LOG(INFO) << "subscribed topic: " << topic;
  }

  // 每一个回调函数都会获得一个线程，单独读取数据
  template <class M>
  void ThreadForCallback(
      const std::string topic,
      const boost::function<void(const M&)>& callback_function) {
    while (!shutdown_) {
      double timestamp;
      const MetaData data = getDataNew(topic, &timestamp);
      if (data.empty()) {
        LOG(WARNING) << "received empty meta data from topic " << topic;
        continue;
      }
      M raw_data;
      if (!raw_data.ParseFromString(data)) {
        LOG(WARNING) << "parse meta data failed from topic " << topic;
        continue;
      }
      callback_function(raw_data);
    }
  }

  std::vector<std::thread> threads_for_callback_;
  std::atomic_bool shutdown_;
  // 测试用
  MyProcess my_process_;
};

REGISTER_COMPONENT("recv", ReceiveComponent);

#endif  // RECV_COMPONENT_H
