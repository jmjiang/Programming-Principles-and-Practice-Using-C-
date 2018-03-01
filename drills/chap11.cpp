#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


int main()
{
  int birth_year = 1991;
  cout << dec << birth_year << "\t(decimal)\n"
       << hex << birth_year << "\t(hexadecimal)\n"
       << oct << birth_year << "\t(octal)\n";

  int current_year = 2018;
  int age = current_year - birth_year;
  cout << dec << age << '\n';
  return 0;
}
