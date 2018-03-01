#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;



/*
 * Checks if a word w1 contains word w2
 * Assume w1 and w2 are words, i.e., no whitespaces
 */
bool contains(string w1, string w2)
{
  if (w1 == w2) return true;
  char w2_initial = w2[0];
  for (int i=0; i<w1.size()-w2.size()+1; ++i) {
    if (w1[i] == w2_initial) {
      string temp = w1.substr(i, w2.size());
      if (temp == w2) return true;
    }
  }
  return false;
}


int main()
{
  string fname = "inputfile.txt";
  string target = "la";

  ifstream file(fname);
  int num = 0;
  while (file.good()) {
    string line;
    getline(file, line);
    istringstream sline;
    sline.str(line);
    for (string word; sline >> word;) {
      if (contains(word, target)) {
        cout << num << ": " << line << '\n';
      }
    }
    ++num;
  }

  file.close();
  return 0;
}
