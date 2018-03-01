#include <iostream>
#include <string>

using namespace std;



void error(string s)
{
  cout << s << endl;
  throw exception();
}

/*
 * greateast common divisor:
 * gcd(a, 0) = 0
 * gcd(a, b) = gcd(b, a mod b)
 * https://en.wikipedia.org/wiki/Greatest_common_divisor#Calculation
 */
int gcd(int a, int b)
{
  if (b == 0) return a;
  return gcd(b, a % b);
}


/*
 * least common multiple:
 * https://en.wikipedia.org/wiki/Least_common_multiple
 */
int lcm(int a, int b)
{
  return abs(a * b) / gcd(a,b);
}



class Rational {
public:
  Rational(int n, int d);

  int get_numerator() const { return numerator; }
  int get_denominator() const { return denominator; }

  double to_double() { return double(numerator) / denominator; }
private:
  int numerator;
  int denominator;
};

Rational::Rational(int n, int d)
  :numerator(n), denominator(d)
{
  if (d == 0) error("[Rational]: denominator cannot be zero");
}

// TODO: assignment operator

ostream & operator<<(ostream & os, Rational r)
{
  if (r.get_denominator() == 1) return os << r.get_numerator();
  return os << r.get_numerator() << '/' << r.get_denominator();
}


Rational operator+(Rational r1, Rational r2)
{
  int r1_denom = r1.get_denominator();
  int r2_denom = r2.get_denominator();
  int common_denom = lcm(r1_denom, r2_denom);
  int new_numerator = r1.get_numerator() * (common_denom / r1_denom) + r2.get_numerator() * (common_denom / r2_denom);
  int factor = gcd(new_numerator, common_denom);
  Rational result(new_numerator / factor, common_denom / factor);
  return result;
}


Rational operator-(Rational r1, Rational r2)
{
  int r1_denom = r1.get_denominator();
  int r2_denom = r2.get_denominator();
  int common_denom = lcm(r1_denom, r2_denom);
  int new_numerator = r1.get_numerator() * (common_denom / r1_denom) - r2.get_numerator() * (common_denom / r2_denom);
  int factor = gcd(new_numerator, common_denom);
  Rational result(new_numerator / factor, common_denom / factor);
  return result;
}


Rational operator*(Rational r1, Rational r2)
{
  int nume = r1.get_numerator() * r2.get_numerator();
  int denom = r1.get_denominator() * r2.get_denominator();
  int factor = gcd(nume, denom);
  Rational result(nume / factor, denom / factor);
  return result;
}


Rational operator/(Rational r1, Rational r2)
{
  int nume = r1.get_numerator() * r2.get_denominator();
  int denom = r1.get_denominator() * r2.get_numerator();
  int factor = gcd(nume, denom);
  Rational result(nume / factor, denom / factor);
  return result;
}


int main()
{
  try {
    cout << "gcd of 48 and 18 = " << gcd(48, 18) << endl;
    cout << "lcm of 21 and 6 = " << lcm(21, 6) << endl;
    Rational r1(2, 5);     // 2/5
    Rational r2(1, 10);    // 1/10
    cout << r1 << " = " << r1.to_double() << endl;
    cout << r2 << " = " << r2.to_double() << endl;
    cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;
    cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;
    cout << r1 << " * " << r2 << " = " << r1 * r2 << endl;
    cout << r1 << " / " << r2 << " = " << r1 / r2 << endl;
    return 0;
  } catch(exception & e) {
    cout << e.what();
    return 1;
  }
}
