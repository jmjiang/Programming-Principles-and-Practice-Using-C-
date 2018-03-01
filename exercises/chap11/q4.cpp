#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

const char decimal = 'd';
const char hexadecimal = 'h';
const char octal = 'o';

char compute_base(string word)
{
  if (word[0] == '0') {
    if (word[1] == 'x') return hexadecimal;
    return octal;
  }
  return decimal;
}



class Int_base {
public:
  Int_base(int n, char c)
    :value(n), base(c) { }
  Int_base(string s);
  char has_base() { return base; }
  int has_value() { return value; }
private:
  int value;
  char base;
};

Int_base::Int_base(string s)
{
  base = compute_base(s);
  if (base == decimal) value = stoi(s);
  else if (base == hexadecimal) value = stoi(s, nullptr, 16);
  else if (base == octal) value = stoi(s, nullptr, 8);
  else {
    cerr << "Not a number" << endl;
    throw exception();
  }
}


int main()
{
  cout << "Enter integers in decimal, octal (with 0 prefix) and/or hexadecimal (with 0x prefix):\n";
  cout << showbase;
  cin.unsetf(ios::dec);
  vector<Int_base> numbers;
  for (string input; cin >> input;) {
    numbers.push_back(Int_base(input));
  }
  for (int i=0; i<numbers.size(); ++i) {
    Int_base n = numbers[i];
    if (n.has_base() == decimal) {
      cout << dec << n.has_value()
           << "\tdecimal\t\tconverts to\t"
           << n.has_value() << "\tdecimal\n";
    } else if (n.has_base() == hexadecimal) {
      cout << hex << n.has_value()
           << "\thexadecimal\tconverts to\t"
           << dec << n.has_value() << "\tdecimal\n";
    } else if (n.has_base() == octal) {
      cout  << octal << n.has_value()
           << "\toctal\t\tconverts to\t"
           << dec << n.has_value() << "\tdecimal\n";
    } else {
      cout << "Invalid base.\n";
    }
  }
  return 0;
}






