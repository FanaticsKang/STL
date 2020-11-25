#pragma once

// include headers that implement a archive in simple text format
#include <boost/serialization/list.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <list>

class gps_position {
 private:
  friend class boost::serialization::access;
  // When the class Archive corresponds to an output archive, the
  // & operator is defined similar to <<.  Likewise, when the class Archive
  // is a type of input archive the & operator is defined similar to >>.
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& degrees;
    ar& minutes;
    ar& seconds;
    ar& data;
  }

 public:
  int degrees = 0;
  int minutes = 0;
  float seconds = 0;
  std::list<float> data;

 public:
  gps_position(){};
  gps_position(int d, int m, float s) : degrees(d), minutes(m), seconds(s) {
    data.emplace_back(degrees);
    data.emplace_back(minutes);
    data.emplace_back(seconds);
  }
};