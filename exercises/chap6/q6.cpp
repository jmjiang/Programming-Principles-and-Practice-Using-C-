#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool contains(vector<string> ss, string s) {
  for (int i=0; i<ss.size(); ++i) {
    if (ss[i] == s) return true;
  }
  return false;
}


bool sentence(vector<string> ss) {
  const int noun_idx = 0;
  const int verb_idx = 1;
  const int con_idx = 2;
  const int interval = 3;

  vector<string> nouns;
  nouns.push_back("birds");
  nouns.push_back("fish");
  nouns.push_back("C++");

  vector<string> verbs;
  verbs.push_back("rules");
  verbs.push_back("fly");
  verbs.push_back("swim");

  vector<string> conjunctions;
  conjunctions.push_back("and");
  conjunctions.push_back("or");
  conjunctions.push_back("but");

  // The length of the sentence should be a multiple of 3
  if (ss.size() % interval != 0) {
    cout << "Not a sentence.\n";
    return false;
  }

  // The last element should be a dot "."
  if (ss[ss.size() - 1] != ".") {
    cout << "A sentence should end with '.'\n";
    return false;
  }

  for (int i=0; i<ss.size()-1; ++i) {
    if ((i == 0) || (i % interval == noun_idx)) {
      if (!contains(nouns, ss[i])) {
        cout << ss[i] << " is not a noun.\n";
        return false;
      }
    } else if (i % interval == verb_idx) {
      if (!contains(verbs, ss[i])) {
        cout << ss[i] << " is not a verb.\n";
        return false;
      }
    } else {
      if (!contains(conjunctions, ss[i])) {
        cout << ss[i] << " is not a noun.\n";
        return false;
      }
    }
  }
  return true;
}
  

int main() {
  cout << "Please enter a sentence, ended with a separate dot.\n";
  string s = " ";
  vector<string> ss;
  while (s != ".") {     // Note: "." is still read into ss
    cin >> s;
    ss.push_back(s);
  }
  if (sentence(ss)) cout << "OK\n";
  else cout << "not OK\n";
}
