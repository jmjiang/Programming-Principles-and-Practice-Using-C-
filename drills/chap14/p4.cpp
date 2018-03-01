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
  void f() { cout << "D1::f()\n"; }
};



int main()
{
  cout << "----- Repeat #1 -----" << endl;
  B1 b1;
  b1.vf();  // B1::vf()
  b1.f();   // B1::f()

  cout << "----- Repeat #2 -----" << endl;
  D1 d1;
  d1.vf();  // D1::vf()
  d1.f();   // D1::f()

  cout << "----- Repeat #3 -----" << endl;
  B1 & b1_ref = d1;
  b1_ref.vf();  // D1::vf()
  b1_ref.f();   // B1::f()

  return 0;
}
