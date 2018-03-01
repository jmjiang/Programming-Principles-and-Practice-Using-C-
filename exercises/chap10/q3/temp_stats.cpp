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


const int not_a_reading = -7777;

struct Reading {
  Reading()
    :day(-1), hour(-1), temperature(0.0) { }
  Reading(int d, int h, double t)
    :day(d), hour(h), temperature(t) { }
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

  int d;
  char ch2;
  int h;
  char ch3;
  double t;
  char ch4;
  is >> d >> ch2 >> h >> ch3 >> t >> ch4;
  cout << "d = " << d << endl;
  cout << "ch2 = " << ch2 << endl;
  cout << "h = " << h << endl;
  cout << "ch3 = " << ch3 << endl;
  cout << "t = " << t << endl;
  cout << "ch4 = " << ch4 << endl;
  /*
   * if (!is || ch2 != ',' || ch3 != ',' || ch4 != ')') {
    cerr << "bad reading";
    throw exception();
  }
  */
  r.day = d;
  r.hour = h;
  r.temperature = t;
  cout << r.day << ", " << r.hour << ", " << r.temperature << endl;
  return is;
}



ostream & operator<<(ostream & os, Reading r)
{
  return os << '(' << r.day << ','
            << r.hour << ','
            << r.temperature <<')';
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
    Reading r1(1, 2, 5.2);
    Reading r2(10, 12, 15.7);
    Reading r3(30, 23, 8.2);
    ost << r1 << endl;
    ost << r2 << endl;
    ost << r3 << endl;
    ost.close();

    ifstream ist(filename);
    if (!ist) {
      cerr << "Cannot open input file";
      throw exception();
    }
    // ist.exceptions(ist.exceptions()|ios_base::badbit);

    vector<Reading> readings;
    for (Reading r; ist >> r;) readings.push_back(r);
    ist.close();
    for (int i=0; i<readings.size(); ++i) cout << readings[i] << endl;

  } catch (exception & e) {
    cout << e.what() << endl;
    return 1;
  }
}







































