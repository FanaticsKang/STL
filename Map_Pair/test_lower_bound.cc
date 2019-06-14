#include <iostream>
#include <map>

int main() {
  std::map<char, int> mymap;
  std::map<char, int>::iterator itlow, itup;

  mymap['a'] = 20;
  // mymap['b'] = 40;
  mymap['c'] = 60;
  mymap['d'] = 80;
  mymap['e'] = 100;
  auto ret_pr = mymap.insert(std::make_pair('b', 40));

  std::cout << "ok? " << ret_pr.first->second << std::endl;
  itlow = mymap.lower_bound('b');  // itlow points to b
  itup = mymap.upper_bound('d');   // itup points to e (not d!)

  std::cout << "itlow: " << itlow->first << std::endl;
  std::cout << "itup: " << itup->first << std::endl;
  mymap.erase(itlow, itup);  // erases [itlow,itup)

  // print content:
  for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end();
       ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}