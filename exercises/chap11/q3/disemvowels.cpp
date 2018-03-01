#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;


bool is_vowel(char c, const string & vowels)
{
  for (int i=0; i<vowels.size(); ++i) {
    if (c == vowels[i]) return true;
  }
  return false;
}

int main()
{
  string vowels = "aeiou";
  ifstream inputfile("input.txt");
  ofstream outputfile("output.txt");
  
  while (inputfile.good()) {
    string line;
    getline(inputfile, line);

    for (int i=0; i<line.size(); ++i) {
      char c = line[i];
      if (!is_vowel(c, vowels)) outputfile << c;
    }
    outputfile << '\n';
  }

  inputfile.close();
  outputfile.close();
  return 0;
}
