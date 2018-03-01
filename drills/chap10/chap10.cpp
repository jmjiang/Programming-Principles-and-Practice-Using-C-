
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Point {
public:
  Point()
    :x(0.0), y(0.0) { }
  Point(double xx, double yy)
    :x(xx), y(yy) { }
  double get_x() const { return x; }
  double get_y() const { return y; }
private:
  double x;
  double y;
};


istream & operator>>(istream & is, Point & p)
{
  double xx;
  double yy;
  char c1;
  char c2;
  char c3;
  is >> c1 >> xx >> c2 >> yy >> c3;
  if (!is) return is;
  if (c1 != '(' || c2 != ',' || c3 != ')') {
    is.clear(ios_base::failbit);
    return is;
  }
  p = Point(xx, yy);
  return is;
}



ostream & operator<<(ostream & os, Point p)
{
  return os << '(' << p.get_x() << ',' << p.get_y() << ')';
}


void write_points_file(const vector<Point> & points, string fname)
{
  ofstream ost(fname);
  if (!ost) {
    cerr << "Cannot open file " << fname;
    throw exception();
  }
  for (int i=0; i<points.size(); ++i) {
    ost << points[i] << '\n';
  }
  ost.close();
}

vector<Point> read_points_file(string fname)
{
  ifstream ist(fname);
  if (!ist) {
    cerr << "Cannot open file " << fname;
    throw exception();
  }
  vector<Point> points;
  for (Point p; ist >> p;) {
    points.push_back(p);
  }
  /* the following does not work
   * it adds a Point(0,0) using the default constructor at the end.
   */
  // while (true) {
  //   Point p;
  //   ist >> p;
  //   points.push_back(p);
  // }
  return points;
}
  



int main()
{
  try {
    string filename = "mydata.txt";
    cout << "Enter 2 points in the form of (x,y):\n";
    vector<Point> original_points;
    for (int i=0; i<2; ++i) {
      Point p;
      cin >> p;
      original_points.push_back(p);
    }
    cout << "original_points are:\n";
    for (int i=0; i<original_points.size(); ++i) {
      cout << original_points[i] << '\n';
    }
    write_points_file(original_points, filename);

    vector<Point> processed_points = read_points_file(filename);
    cout << "processed_points are:\n";
    for (int i=0; i<processed_points.size(); ++i) {
      cout << processed_points[i] << '\n';
    }

    if (original_points.size() != processed_points.size()) cout << "Something's wrong!\n";

    return 0;
  } catch(exception & e) {
    cout << e.what() << endl;
    return 1;
  }
}
