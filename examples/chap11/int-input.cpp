#include <iostream>

using namespace std;

int main()
{
  cout << "----- P384 -----\n";
  int a, b, c;
  /*
  cout << "Enter 1234 0x4d2 02322:\n";
  cin >> a >> b >> c;  // WRONG! 1234 is read into a, 0 is in b, x is not int so 0 is in c
  cout << a << '\t' << b << '\t' << c << '\n';
  */

  cin.unsetf(ios::dec);
  cout << "Enter 1234 0x4d2 02322:\n";
  cin >> a >> b >> c;
  cout << a << '\t' << b << '\t' << c << '\n';  // 1234 1234 1234
  cout << '\n';

  cin.unsetf(ios::oct);   // why need this?
  cout << "Enter 1234 0x4d2 02322:\n";
  cin >> a >> b >> c;
  cout << a << '\t' << b << '\t' << c << '\n';  // 1234 1234 1234
  cout << '\n';

  cin.unsetf(ios::hex);   // why need this?
  cout << "Enter 1234 0x4d2 02322:\n";
  cin >> a >> b >> c;
  cout << a << '\t' << b << '\t' << c << '\n';  // 1234 1234 1234

  return 0;
}
