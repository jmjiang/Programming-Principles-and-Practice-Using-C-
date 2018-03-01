#include <sstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;



class Punct_stream
{
public:
  Punct_stream(istream & is)
    :source(is), sensitive(true) { }
  void whitespace(const string & s)
    { white = s; }
  bool is_whitespace(char c);
  void case_sensitive(bool b)
    { sensitive = b; }
  bool is_case_sensitive()
    { return sensitive; }
  Punct_stream & operator>>(string & s);
  operator bool();

private:
  istream & source;
  istringstream buffer;
  string white;
  bool sensitive;
};


bool Punct_stream::is_whitespace(char c)
{
  for (int i=0; i<white.size(); ++i) {
    if (white[i] == c) return true;
  }
  return false;
}


Punct_stream::operator bool()
{
  return !(source.fail() || source.bad()) && source.good();
}


Punct_stream & Punct_stream::operator>>(string & s)
{
  while (!(buffer >> s)) {
    if (buffer.bad() || !source.good()) return *this;
    buffer.clear();

    string line;
    getline(source, line);

    for (int i=0; i<line.size(); ++i) {
      char & c = line[i];
      if (is_whitespace(c)) c = ' ';
      else if (!is_case_sensitive()) c = tolower(c);
    }

    buffer.str(line);
  }
  return *this;
}

int main()
{
  Punct_stream ps(cin);
  ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");
  ps.case_sensitive(false);

  cout << "Please enter words\n";
  vector<string> words;
  for (string word; ps>>word;) {
    words.push_back(word);
  }
  for (int i=0; i<words.size(); ++i) {
    cout << words[i] << '\n';
  }

  return 0;
}



























