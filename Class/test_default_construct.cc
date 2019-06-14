
class Test {
 public:
  Test(const int& i) : m_int(i){};
  const int& m_int;
};

int main() {
  int i = 10;
  int j = 10;

  Test t(i);
  Test t2(j);
  // t2 = t; //error
}