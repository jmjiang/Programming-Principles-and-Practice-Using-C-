// Write out a table of characters with their corresponding integer values

#include <iostream>
using namespace std;

int main() {

  const int num_letters = 26;
  int letter = 'a'-1;

  int i = 0;
  while (i < num_letters) {
    letter = letter + 1;
    cout << char(letter) << "  " << letter << '\n';
    ++i;
  }

  return 0;
}
