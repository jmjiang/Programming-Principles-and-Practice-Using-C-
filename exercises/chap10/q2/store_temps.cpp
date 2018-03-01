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




int main()
{
  try {
    string filename = "raw_temps.txt";
    ofstream ost(filename);
    if (!ost) {
      cerr << "can't open output file";
      throw exception();
    }
    ost << "(1 2 5.2)\n";
    ost << "(10 12 15.7)\n";
    ost << "(30 23 8.2)\n";
    ost.close();
  } catch (exception & e) {
    cout << e.what() << endl;
    return 1;
  }
}







































