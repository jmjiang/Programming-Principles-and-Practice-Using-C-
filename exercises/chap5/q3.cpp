#include <iostream>
using namespace std;

double ctok(double c) {
  double k = c + 273.15;
  return k;
}

int main() {
  double c = 0;
  cin >> c;
  if (c < -273.15) {
    cerr << "Unreachable temperature.\n";
    return 1;
  }
  double k = ctok(c);
  cout << k << '\n';

  return 0;
}
