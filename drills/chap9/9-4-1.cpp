#include <iostream>
#include <string>

using namespace std;

void error(string s) {
  cout << s << '\n';
  throw exception();
}


struct Date {
  int y;
  int m;
  int d;
};



void init_day(Date & dd, int y, int m, int d)
{
  if ((d < 1) || (d > 31)) error("Invalid day: needs to be in [1,31]");
  if ((m < 1) || (m > 12)) error("Invalid day: needs to be in [1,12]");
  dd.y = y;
  dd.m = m;
  dd.d = d;
}



void add_day(Date & dd, int n)
{
  int d = dd.d + n;
  if ((d < 1) || (d > 31)) error("The resulting date is invalid: needs to be in [1,31]");
  dd.d = d;
}



ostream & operator<<(ostream & os, const Date & d)
{
  return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}



int main()
{
  try {
    Date today;
    init_day(today, 1978, 6, 25);

    Date tomorrow = today;
    add_day(tomorrow, 1);

    cout << "today: " << today << '\n';
    cout << "tomorrow: " << tomorrow << '\n';

    return 0;
  } catch (exception & e) {
    cout << e.what();
    return 1;
  }
}
