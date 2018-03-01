#include <iostream>

using namespace std;



class B1 {
public:
  virtual void vf() { cout << "B1::vf()\n"; }
  void f() { cout << "B1::f()\n"; }
};


class D1 : public B1 {
public:
  void vf() override { cout << "D1::vf()\n"; }
};



int main()
{
  cout << "----- #1 -----" << endl;
  B1 b1;
  b1.vf();  // B1::vf()
  b1.f();   // B1::f()

  cout << "----- #2 -----" << endl;
  D1 d1;
  d1.vf();  // D1::vf()
  d1.f();   // B1::f()

  cout << "----- #3 -----" << endl;
  B1 & b1_ref = d1;
  b1_ref.vf();  // D1::vf()
  b1_ref.f();   // B1::f()

  return 0;
}
