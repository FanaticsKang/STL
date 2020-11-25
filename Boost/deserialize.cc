#include <fstream>
#include <iostream>
#include "gps.h"

int main(int argv, char** argc) {
  if (argv != 2) {
    std::cerr << "use serialization /path/to/input" << std::endl;
    return -1;
  }
  std::ifstream out_file(argc[1]);
  gps_position g;
  int data;

  std::cout << "before gps value: " << g.degrees << ", " << g.minutes << ", "
            << g.seconds << std::endl;
  // save data to archive
  {
    boost::archive::text_iarchive ia(out_file);
    // write class instance to archive
    ia >> g;
    ia >> data;
    // archive and stream closed when destructors are called
  }
  std::cout << "after gps value: " << g.degrees << ", " << g.minutes << ", "
            << g.seconds << std::endl;
  std::cout << "Out data: " << data << std::endl;
  for(float& tmp:g.data){
    std::cout << tmp << std::endl;
  }
}