#include <iostream>

using namespace std;


int factorial(int n)
{
  if (n<0) {
    cerr << "[factorial] argument must be a positive integer";
    throw exception();
  }
  if ((n==0) || (n==1)) return 1;
  return n*factorial(n-1);
}


int main()
{
  try {
    int x = 5;
    cout << "factorial(" << x << ") = " << factorial(x) << endl;
    int y = 3;
    cout << "factorial(" << y << ") = " << factorial(y) << endl;
    return 0;
  } catch (exception & e) {
    cout << e.what() << endl;
    return 1;
  }

}
