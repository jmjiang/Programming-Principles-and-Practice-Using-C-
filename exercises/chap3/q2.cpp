// read name and age

#include <iostream>
#include <string>
using namespace std;

int main() {
  const double mile_to_km = 1.609;
  cout << "Enter a number of miles\n";
  double mile = 0.0;
  cin >> mile;
  cout << mile << " miles = " << mile * mile_to_km << " kilometers\n";
  return 0;
}
