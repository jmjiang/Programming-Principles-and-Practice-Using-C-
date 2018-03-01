/*
 * The Class definition drill in Chapter 15
 */

#include <iostream>
#include <string>

using namespace std;


const string non_name_char = ";:\"'[]*&^%$#@!";


bool not_name(string s)
{
  for (int i=0; i<s.size(); ++i) {
    char c = s[i];
    for (int j=0; j<non_name_char.size(); ++j) {
      if (c == non_name_char[j]) {
        return true;
      }
    }
  }
  return false;
}


struct Person {
  Person()
    :f(""), l(""), n(0) { }
  Person(string s1, string s2, int nn);

  string first_name() const { return f; }
  string last_name() const { return l; }
  void set_first_name(string ss);
  void set_last_name(string ss);

  int age() const { return n; }
  void set_age(int nn);
private:
  string f;
  string l;
  int n;
};


Person::Person(string s1, string s2, int nn)
{
  if ((nn < 0) || (nn > 149)) {
    cerr << "[Person] age out of range";
    throw exception();
  }
  if ((not_name(s1)) || (not_name(s2))) {
    cerr << "[Person] name cannot contain characters " << non_name_char;
    throw exception();
  }
  f = s1;
  l = s2;
  n = nn;
}


void Person::set_first_name(string ss)
{
  if (not_name(ss)) {
    cerr << "[set_first_name] name cannot contain characters " << non_name_char;
    throw exception();
  }
  f = ss;
}


void Person::set_last_name(string ss)
{
  if (not_name(ss)) {
    cerr << "[set_last_name] name cannot contain characters " << non_name_char;
    throw exception();
  }
  l = ss;
}


void Person::set_age(int nn)
{
  if ((nn < 0) || (nn > 149)) {
    cerr << "[set_age] age out of range";
    throw exception();
  }
  n = nn;
}



istream & operator>>(istream & is, Person & p)
{
  char ch1 = 0;
  char ch2 = 0;
  char ch3 = 0;

  string fname;
  string lname;
  int age;

  if (is >> ch1 >> fname >> lname >> ch2 >> age >> ch3) {
    if ((ch1 != '(') || (ch2 != ',') || (ch3 != ')')) {
      cerr << "[input] wrong format";
      throw exception();
      return is;
    }
  } else {
    return is;
  }
  p.set_first_name(fname);
  p.set_last_name(lname);
  p.set_age(age);
  return is;
}


ostream & operator<<(ostream & os, Person & p)
{
  return os << '(' << p.first_name() << ' ' << p.last_name() << " , " << p.age() << ')';
}


int main()
{
  try {
    Person p2;
    cin >> p2;
    cout << p2 << endl;
    
    cout << "set first name to lala:\n";
    p2.set_first_name("lala*");
    cout << "modified: " << p2 << endl;
    return 0;
  } catch (exception & e) {
    cout << e.what() << endl;
    return 1;
  }
}











