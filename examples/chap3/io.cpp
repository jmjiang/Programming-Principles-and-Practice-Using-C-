// read name and age
/* Testing:
 * When the second input for age: (doesn't matter if an initial value for age is provided)
 *   is a string but start with numbers:
 *     age is the prefix of the string that consists of numbers
 *     e.g., 53/ji -> 53
 *   is a string but start with letters:
 *     age is 0
 *   is a number but not an integer:
 *     age is the prefix part that consists of only numbers 0-9
 *     e.g., 3.9 -> 3
 * When input more than two "words": all but the first two are ignored
 */


#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Please enter your first name and age:\n";
  string first_name;
  int age;
  cin >> first_name;
  cin >> age;
  cout << "Hello, " << first_name << " (age " << age << ")\n";
  return 0;
}
