#include <iostream>
#include <string>
using namespace std;

int main() {
  int min = 1;
  int max = 100;
  cout << "Please think of an integer between " << min << " and " << max << '\n';
  cout << "And don't tell me what it is. Let me guess.\n";
  cout << "Enter yes or no for the questions I ask you.\n";

  string input = " ";
  int bar = (min + max) / 2;
  cout << "Is the number less than or equal to " << bar << "?\n";
  while (cin >> input) {
    if (input == "yes") max = bar;
    else if (input == "no") min = bar + 1;

    if (min == max) {
      cout << "You guessed " << min << "!\n";
      break;
    } else {
      bar = (min + max) / 2;
      cout << "Is the number less than or equal to " << bar << "?\n";
    }
  }

  return 0;
}
