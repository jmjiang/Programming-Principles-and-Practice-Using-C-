#include <vector>
#include <iostream>

using namespace std;



class Iterator{
public:
  virtual double* next() =0;
  virtual bool end() =0;
};


class Vector_iterator : public Iterator {
public:
  Vector_iterator(vector<double> v);
  double* next() override;
  bool end() override;
private:
  vector<double> vec;
  int idx;
};


Vector_iterator::Vector_iterator(vector<double> v)
{
  vec = v;
  idx = -1;
}


bool Vector_iterator::end()
{
  if (idx == vec.size() - 1) return true;
  return false;
}


double* Vector_iterator::next()
{
  if (vec.size() == 0) return 0;
  if (end()) return 0;
  ++idx;
  return &vec[idx];
}




void print(Iterator & it)
{
  while (!it.end()) cout << *it.next() << '\t';   // * dereference operator
}

int main()
{
  vector<double> v1;
  Vector_iterator v1_it(v1);
  cout << "v1 = ";
  print(v1_it);
  cout << endl;

  vector<double> v2;
  v2.push_back(2.1);
  Vector_iterator v2_it(v2);
  cout << "v2 = ";
  print(v2_it);
  cout << endl;

  vector<double> v3;
  v3.push_back(3.1);
  v3.push_back(3.2);
  v3.push_back(3.3);
  Vector_iterator v3_it(v3);
  cout << "v3 = ";
  print(v3_it);
  cout << endl;
  
  return 0;
}








