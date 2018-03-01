#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;



struct Person {
  Person(string l, string f, string p, string e)
    :lastname(l), firstname(f), phone(p), email(e) { }
  string lastname;
  string firstname;
  string phone;
  string email;
};



int main()
{
  Person p1("Jiang", "Jiaming", "9192740745", "jm.jiang5@gmail.com");
  Person p2("Huang", "Qingyun", "9199169727", "qyhuang@utexas.edu");

  vector<Person> p;
  p.push_back(p1);
  p.push_back(p2);

  string empty = " ";

  cout << setw(10) << "last name" << setw(4) << empty << '|'
       << setw(10) << "first name" << setw(4) << empty << '|'
       << setw(10) << "phone" << '|'
       << setw(20) << "email" << "\n";
  for (int i=0; i<p.size(); ++i) {
    cout << setw(10) << p[i].lastname << setw(4) << empty << '|'
         << setw(10) << p[i].firstname << setw(4) << empty << '|'
         << setw(10) << p[i].phone<< '|'
         << setw(20) << p[i].email<< "\n";
  }

  return 0;
}
