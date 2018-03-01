// compute the square of an integer

#include <iostream>
using namespace std;

int abs(int x) {
  if (x < 0) return -1 * x;
  else return x;
}

int square(int x) {
  int result = 0;
  int pos_x = abs(x);

  for (int i=0; i<pos_x; ++i) {
    result += pos_x;
  }
  return result;
}

int main() {
  cout << square(2) << '\n';
  cout << square(5) << '\n';
  cout << square(-5) << '\n';
  cout << square(0) << '\n';

  return 0;
}
