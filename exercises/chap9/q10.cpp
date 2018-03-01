#include <iostream>
#include <string>

using namespace std;

void error(string s) {
  cout << s << '\n';
  throw exception();
}



enum Month {
  jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};


class Date {
  int y;
  Month m;
  int d;
public:
  Date(int y, Month m, int d);
  void add_day(int n);
  Month month() const { return m; }
  int day() const { return d; }
  int year() const { return y; }
};



Date::Date(int yy, Month mm, int dd)
{
  if ((dd < 1) || (dd > 31)) error("Invalid day: needs to be in [1,31]");
  if ((int(mm) < 1) || (int(mm) > 12)) error("Invalid month");
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



bool leapyear(int y)
{
  if (y % 4 == 0) return true;
  return false;
}



int main()
{
  try {
    Date today(1978, jun, 25);

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
