#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


vector<string> split(const string & s)
{
  vector<string> words;
  istringstream ss;
  ss.str(s);
  for (string word; ss >> word;) words.push_back(word);
  return words;
}

int main()
{
  string s = "jiaming jiang alal";
  vector<string> splitted = split(s);
  for (int i=0; i<splitted.size(); ++i) cout << splitted[i] << endl;
}
