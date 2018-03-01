#include <iostream>

using namespace std;



int main()
{
  double temp = 1234.56789;
  cout << temp << "\t\t(defaultfloat)\n"            // 1234.57
       << fixed << temp << "\t(fixed)\n"            // 1234.567890
       << scientific << temp << "\t(scientific)\n"; // 1.234568e+03
  cout << '\n';

  temp = 1234.5678911110238934;
  cout << defaultfloat << temp << "\t(defaultfloat)\n" // 1234.57
       << fixed << temp << "\t(fixed)\n"               // 1234.567891
       << scientific << temp << "\t(scientific)\n";    // 1.234568e+03
  cout << '\n';

  temp = 1234.5;
  cout << defaultfloat << temp << "\t(defaultfloat)\n" // 1234.5
       << fixed << temp << "\t(fixed)\n"               // 1234.500000
       << scientific << temp << "\t(scientific)\n";    // 1.234500e+03
  cout << '\n';

  temp = 12345678.9;
  cout << defaultfloat << temp << "\t(defaultfloat)\n" // 1.23457e+07
       << fixed << temp << "\t(fixed)\n"               // 12345678.900000
       << scientific << temp << "\t(scientific)\n";    // 1.234568e+07
  cout << '\n';

  temp = 1234567.0;
  cout << defaultfloat << temp << "\t(defaultfloat)\n" // 1.23457e+07
       << fixed << temp << "\t(fixed)\n"               // 12345678.900000
       << scientific << temp << "\t(scientific)\n";    // 1.234568e+07
  cout << '\n';
  return 0;
}
