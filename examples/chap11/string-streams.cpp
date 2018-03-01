#include <sstream>
#include <iostream>

using namespace std;



// P394
double str_to_double(string s)
{
  istringstream is(s);
  double d;
  is >> d;
  if (!is) {
    cout << "double format error" << endl;
    throw exception();
  }
  return d;
}


// P395
string construct(double d)
{
  ostringstream os;
  os << "myfile" << d;
  return os.str();
}



int main()
{
  try {
    double temp = str_to_double("23.9");
    cout << temp << endl;
    cout << construct(temp) << endl;
    return 0;
  } catch (exception e) {
    cerr << e.what() << endl;
    return 1;
  }
}
