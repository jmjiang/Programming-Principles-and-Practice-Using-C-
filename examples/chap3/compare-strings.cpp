
#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Please enter two words: \n";
  string first;
  string second;
  cin >> first >> second;
  if (first == second) cout << "they are the same\n";
  else if (first < second) cout << first << " is alphabetically before " << second << "\n";
  else  cout << first << " is alphabetically after " << second << "\n";
  return 0;
}
