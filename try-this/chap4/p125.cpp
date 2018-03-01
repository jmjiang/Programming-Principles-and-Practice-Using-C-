// Bleeps out words that I don't like

#include <iostream>
#include <vector>
using namespace std;

bool in(string w, vector<string> words) {
  for (int i=0; i<words.size(); ++i) {
    if (words[i] == w) return true;
  }
  return false;
}

int main(){
  vector<string> dislike;
  dislike.push_back("pork");
  dislike.push_back("bug");

  vector<string> words;
  for (string temp; cin >> temp;) {
    words.push_back(temp);
  }

  cout << "After bleeping:\n";
  for (int i=0; i<words.size(); ++i) {
    if (in(words[i], dislike)) cout << "BLEEP\n";
    else cout << words[i] << '\n';
  }

  return 0;
}
