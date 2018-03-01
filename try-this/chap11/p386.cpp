#include <iostream>

using namespace std;



int main()
{
  double temp = 1234567.89;
  cout << temp << "\t(defaultfloat)\n"              // 1.23457e+06
       << fixed << temp << "\t(fixed)\n"            // 1234567.890000
       << scientific << temp << "\t(scientific)\n"; // 1.234568e+06

  return 0;
}
