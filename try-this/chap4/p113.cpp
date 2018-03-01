// Write out a table of characters with their corresponding integer values

#include <iostream>
using namespace std;

int main() {

  const int num_letters = 26;
  int letter = 'a'-1;

  for (int i=0; i<num_letters; ++i) {
    letter = letter + 1;
    cout << char(letter) << "  " << letter << '\n';
  }

  cout << "Uppercase letters and digits:\n";
  int upper_letter = 'A'-1;

  for (int i=0; i<num_letters; ++i) {
    upper_letter = upper_letter + 1;
    cout << char(upper_letter) << "  " << upper_letter << '\n';
  }

  return 0;
}
