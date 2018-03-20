#include <iostream>

using namespace std;



class Myvector {
  int sz;
  double* elem;
public:
  Myvector(int s);   // constructor
  ~Myvector();       // destructor

  int size() const { return sz; }

  double get(int n) const { return elem[n]; }
  void set(int n, double v) { elem[n] = v; }
};


Myvector::Myvector(int s)
  :sz(s), elem(new double[s])
{
  for (int i=0; i<s; ++i) elem[i] = 0;
}


Myvector::~Myvector()
{
  delete[] elem;
}


int main()
{
  Myvector temp(5);
  for (int i=0; i<temp.size(); ++i) {
    temp.set(i, i);
  }
  for (int i=0; i<temp.size(); ++i) {
    cout << temp.get(i) << endl;
  }
  return 0;
}
