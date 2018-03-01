#include <iostream>
#include <string>

using namespace std;

void error(string s) {
  cout << s << '\n';
  throw exception();
}


class Date {
  int y;
  int m;
  int d;
public:
  Date(int y, int m, int d);
  void add_day(int n);
  int month() const { return m; }
  int day() const { return d; }
  int year() const { return y; }
};



Date::Date(int yy, int mm, int dd)
{
  if ((dd < 1) || (dd > 31)) error("Invalid day: needs to be in [1,31]");
  if ((mm < 1) || (mm > 12)) error("Invalid day: needs to be in [1,12]");
  y = yy;
  m = mm;
  d = dd;
}



void Date::add_day(int n)
{
  int dd = d + n;
  if ((dd < 1) || (dd > 31)) error("The resulting date is invalid: needs to be in [1,31]");
  d = dd;
}



ostream & operator<<(ostream & os, const Date & d)
{
  return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}



int main()
{
  try {
    Date today(1978, 6, 25);

    Date tomorrow = today;
    tomorrow.add_day(1);

    cout << "today: " << today << '\n';
    cout << "tomorrow: " << tomorrow << '\n';

    return 0;
  } catch (exception & e) {
    cout << e.what();
    return 1;
  }
}
