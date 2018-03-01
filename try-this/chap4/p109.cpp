// convert from yen, euros, and pounds into dollars.

#include <iostream>
using namespace std;

int main() {
  const double yen_to_dollar = 0.0088;
  const double euro_to_dollar = 1.18;
  const double pound_to_dollar = 1.34;

  double input = 0;
  char unit = ' ';

  cout << "Please enter a value followed by a unit (y, e, or p):\n";
  cin >> input >> unit;

  switch (unit) {
    case 'y':
      cout << input << "yen == " << input * yen_to_dollar << "dollar\n";
      break;
    case 'e':
      cout << input << "euro == " << input * euro_to_dollar << "dollar\n";
      break;
    case 'p':
      cout << input << "pound == " << input * pound_to_dollar << "dollar\n";
      break;
    default:
      cout << "Sorry, I don't know a unit called '" << unit << "'\n";
      break;
  }

  return 0;
}
