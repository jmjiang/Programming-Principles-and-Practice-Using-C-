#include <string>
#include <vector>
#include <iostream>
#include <sstream>   // for stringstream
#include <iterator>

using namespace std;


/*
 * Global constants
 */
const char isbn_delim = '-';
const int num_isbn_parts = 4;


/*
 * utility functions
 */

void error(string s) {
  cout << s << '\n';
  throw exception();
}


// Split a string by deliminator
// Copied from:
// https://stackoverflow.com/questions/236129/the-most-elegant-way-to-iterate-the-words-of-a-string
// Need to include libraries string, sstrea, vector, iterator
template<typename Out>
void split(const string &s, char delim, Out result) {
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    *(result++) = item;
  }
}

vector<string> split(const string & s, char delim) {
  vector<string> elems;
  split(s, delim, back_inserter(elems));
  return elems;
}


/*
 * Class for Date
 */
enum Month {
  jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};


class Date {
  int y;
  Month m;
  int d;
public:
  Date(int y, Month m, int d);
  void add_day(int n);
  Month month() const { return m; }
  int day() const { return d; }
  int year() const { return y; }
};


Date::Date(int yy, Month mm, int dd)
{
  if ((dd < 1) || (dd > 31)) error("Invalid day: needs to be in [1,31]");
  if ((int(mm) < 1) || (int(mm) > 12)) error("Invalid month");
  y = yy;
  m = mm;
  d = dd;
}


void Date::add_day(int n)
{
  int dd = d + n;
  if ((dd < 1) || (dd > 31)) error("The resulting date is invalid: needs to be in [1,31]");
  d = dd;
}


ostream & operator<<(ostream & os, const Date & d)
{
  return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}



/*
 * Class for Book
 */

enum Genre {
  fiction, nonfiction, periodical, biography, children
};


// some helper functions that need to be defined before Book

// check whether a string is in the correct for an isbn
// isbn is only in the format of n-n-n-x
// n: an integer
// x: a digit or a letter
bool is_isbn(string n)
{
  vector<string> splitted_isbn = split(n, isbn_delim);

  // should have four parts
  if (splitted_isbn.size() != num_isbn_parts) return false;

  // the last x is a digit or a letter
  string last = splitted_isbn[splitted_isbn.size() - 1];
  if (last.size() != 1) return false;
  char ch = last[0];
  if (!isalpha(ch) && !isdigit(ch)) return false;

  // the first three parts are integers
  for (int i=0; i<splitted_isbn.size()-1; ++i) {
    string w = splitted_isbn[i];
    for (int j=0; j<w.size(); ++j) {
      if (!isdigit(w[j])) return false;
    }
  }
  return true;
}


class Book {
public:
  // constructor
  Book(string n, string t, string a, Date d, bool o);
  // accessors
  string get_isbn() const { return isbn; }
  string get_title() const { return title; }
  string get_author() const { return author; }
  Date get_cp_date() const { return cp; }
  bool is_checked_out() const { return out; }
  Genre get_genre() const { return genre; }
  // other
  void check_in();
  void check_out();
private:
  string isbn;
  string title;
  string author;
  Date cp;
  bool out;
  Genre genre;
};


Book::Book(string n, string t, string a, Date d, bool o)
  :isbn(n), title(t), author(a), cp(d), out(o)
{
  if (!is_isbn(n)) error("[Book]: wrong format of isbn");
}


void Book::check_in()
{
  if (!out) {
    cout << "Book '" << title << "' already checked in.\n";
    return;
  }
  out = false;
}

void Book::check_out()
{
  if (out) {
    cout << "Book '" << title << "' already checked out.\n";
    return;
  }
  out = true;
}



// helper functions
bool operator==(Book b1, Book b2)
{
  if (b1.get_isbn() == b2.get_isbn()) return true;
  return false;
}

bool operator!=(Book b1, Book b2)
{
  return !(b1 == b2);
}

ostream & operator<<(ostream & os, Book b)
{
  return os << "Title: " << b.get_title() << '\n'
            << "Author: " << b.get_author() << '\n'
            << "ISBN: " << b.get_isbn() << '\n';
}


int main()
{
  try {
    cout << "Test ISBN format...\n";
    string temp = "398-34738-347-2";
    vector<string> splitted_temp = split(temp, '-');
    for (int i=0; i<splitted_temp.size(); ++i) {
      cout << splitted_temp[i] << '\n';
    }
    if (is_isbn(temp)) cout << "Success.\n";
    else cout << "Fail.\n";
    return 0;
  } catch (exception & e) {
    return 1;
  }
}








