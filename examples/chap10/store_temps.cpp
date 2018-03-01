#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;



void end_of_loop(istream & ist, char term, const string & message)
{
  if (ist.fail()) {
    ist.clear();
    char ch;
    if (ist >> ch && ch == term) return;
    cerr << message;
    throw exception();
  }
}


int month_to_int(string s)
{
  if (s == "jan") return 0;
  if (s == "feb") return 1;
  if (s == "mar") return 2;
  if (s == "apr") return 3;
  if (s == "may") return 4;
  if (s == "jun") return 5;
  if (s == "jul") return 6;
  if (s == "aug") return 7;
  if (s == "sep") return 8;
  if (s == "oct") return 9;
  if (s == "nov") return 10;
  if (s == "dec") return 11;
  return -1;
}


const int not_a_reading = -7777;
const int not_a_month = -1;
const int not_a_year = -1;

struct Day {
  Day();
  vector<double> hour;
};

Day::Day()
{
  for (int i=0; i<24; ++i) hour.push_back(not_a_reading);
}


struct Month {
  Month();
  int month;
  vector<Day> day;
};

Month::Month()
{
  month = not_a_month;
  for (int i=0; i<32; ++i) {
    Day new_day;
    day.push_back(new_day);
  }
}


struct Year {
  Year();
  int year;
  vector<Month> month;
};

Year::Year()
{
  year = not_a_year;
  for (int i=0; i<12; ++i) {
    Month new_month;
    month.push_back(new_month);
  }
}


struct Reading {
  int day;
  int hour;
  double temperature;
};


const int implausible_min = -200;
const int implausible_max = 200;

bool is_valid(const Reading & r)
{
  if (r.day < 1 || 31 < r.day) return false;
  if (r.hour < 0 || 23 < r.hour) return false;
  if (r.temperature < implausible_min || implausible_max < r.temperature) return false;

  return true;
}



istream & operator>>(istream & is, Reading & r)
{
  char ch1;
  if (is >> ch1 && ch1 != '(') {
    is.unget();
    is.clear(ios_base::failbit);
    return is;
  }

  char ch2;
  int d;
  int h;
  double t;
  is >> d >> h >> t >> ch2;
  if (!is || ch2 != ')') {
    cerr << "bad reading";
    throw exception();
  }
  r.day = d;
  r.hour = h;
  r.temperature = t;
  return is;
}


istream & operator>>(istream & is, Month & m)
{
  char ch = 0;
  if (is >> ch && ch != '{') {
    is.unget();
    is.clear(ios_base::failbit);
    return is;
  }

  string month_marker;
  string mm;
  is >> month_marker >> mm;
  if (!is || month_marker != "month") {
    cerr << "bad start of month";
    m.month = month_to_int(mm);
  }

  int duplicates = 0;
  int invalids = 0;
  for (Reading r; is >> r;) {
    if (is_valid(r)) {
      if (m.day[r.day].hour[r.hour] != not_a_reading) ++duplicates;
      m.day[r.day].hour[r.hour] = r.temperature;
    } else {
      ++ invalids;
    }
  }
  if (invalids) {
    cerr << invalids << "invalid readings in month";
    throw exception();
  }
  if (duplicates) {
    cerr << duplicates << "duplicate readings in month";
    throw exception();
  }
  end_of_loop(is, '}', "bad end of month");
  return is;
}



istream & operator>>(istream & is, Year & y)
{
  char ch;
  is >> ch;
  if (ch != '{') {
    is.unget();
    is.clear(ios::failbit);
    return is;
  }

  string year_marker;
  int yy;
  is >> year_marker >> yy;
  if (!is || year_marker != "year") {
    cerr << "bad start of year";
    throw exception();
  }
  y.year = yy;

  for (Month m; is >> m;) {
    y.month[m.month] = m;
    m = Month();
  }
  end_of_loop(is, '}', "bad end of year");
  return is;
}


int main()
{
  try {
    string filename = "raw_temps.txt";
    ofstream ost(filename);
    if (!ost) {
      cerr << "can't open output file";
      throw exception();
    }
    ost << "{year 1990 }\n";
    ost << "{year 1991 { month jun }}\n";
    ost << "{ year 1992 { month jan ( 1 0 61.5) } {month feb (1 1 64) (2 2 65.2) } }\n";
    ost << "{year 2000\n";
    ost << "      { month feb (1 1 68 ) (2 3 66.66 ) ( 1 0 67.2)}\n";
    ost << "      {month dec (15 15 –9.2 ) (15 14 –8.8) (14 0 –2) } }\n";
    ost.close();
  } catch (exception & e) {
    cout << e.what() << endl;
    return 1;
  }
}







































