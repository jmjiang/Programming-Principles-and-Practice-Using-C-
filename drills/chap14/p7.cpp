#include <iostream>
#include <string>

using namespace std;



class B2 {
public:
  virtual void pvf() =0;
};


class D21 : public B2 {
public:
  string s;
  void pvf() override { cout << "D21::" << s << '\n'; }
};


class D22 : public B2 {
public:
  int n;
  void pvf() override { cout << "D22::" << n << '\n'; }
};


void f(B2 & b2)
{
  b2.pvf();
}



int main()
{
  D21 d21;
  d21.s = "23";
  f(d21);  // D21::23

  D22 d22;
  d22.n = 23;
  f(d22);  // D22:23

  return 0;
}
