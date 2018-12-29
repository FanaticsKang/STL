#include "StringBad.h"
#include <cstring>

using std::cout;
int StringBad::num_string = 0;

StringBad::StringBad(const char *s) {
  len = std::strlen(s);
  str = new char[len + 1];
  std::strcpy(str, s);
  num_string++;
  cout << num_string << ": \"" << str << "\" object created\n";
}

StringBad::StringBad() {
  len = 4;
  str = new char[4];
  std::strcpy(str, "C++");
  num_string++;
  cout << num_string << ": \"" << str << "\" object created\n";
}

//Added to fix
StringBad::StringBad(const StringBad& st){
  len = st.len;
  str = new char[len + 1];
  std::strcpy(str, st.str);
  num_string++;
  cout << num_string << ": \"" << str << "\" object created\n";
}

//Added to fix
StringBad & StringBad::operator=(const StringBad& st){
  if(this == &st)
      return *this;
  delete []str;
  len = st.len;
  str = new char[len + 1];
  std::strcpy(str, st.str);  
  return *this;
  
}




StringBad::~StringBad() {
  cout << "\"" << str << "\" object deleted. ";
  --num_string;
  cout << num_string << " left\n";
  delete[] str;
}

std::ostream & operator<<(std::ostream &os, const StringBad &st)
{
  os << st.str;
  return os;
}
