#include <fstream>
#include <iostream>
#include "gps.h"

int main(int argv, char** argc) {
  if (argv != 2) {
    std::cerr << "use serialization /path/to/output" << std::endl;
    return -1;
  }
  std::ofstream out_file(argc[1]);
  const gps_position g(35, 59, 24.567f);
  int out_data = 10;

  // save data to archive
  {
    boost::archive::text_oarchive oa(out_file);
    // write class instance to archive
    oa << g;
    oa << out_data;
    // archive and stream closed when destructors are called
  }
}