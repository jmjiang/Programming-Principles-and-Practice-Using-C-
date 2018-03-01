#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


bool contains(const string & w, const char c)
{
  for (int i=0; i<w.size(); ++i) {
    if (w[i] == c) return true;
  }
  return false;
}

vector<string> split(const string & s, const string & w)
{
  stringstream ss;
  for (int i=0; i<s.size(); ++i) {
    if (!contains(w, s[i])) os << s[i];
    else os << ' ';
  }
  vector<string> words;
  for (string word; ss >> word;) words.push_back(word);
  return words;
}

int main()
{
  string s = "jiaming jiang alal";
  string w = "a";
  vector<string> splitted = split(s, w);
  for (int i=0; i<splitted.size(); ++i) cout << splitted[i] << endl;
  return 0;
}
