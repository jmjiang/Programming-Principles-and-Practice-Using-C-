// read name and age
// the age s input in years but output as months


#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Please enter your first name and age:\n";
  string first_name = "NULL";
  double age_year = -1.0;
  cin >> first_name;
  cin >> age_year;
  double age_month = age_year * 12;
  cout << "Hello, " << first_name << " (age in month: " << age_month << ")\n";
  return 0;
}
