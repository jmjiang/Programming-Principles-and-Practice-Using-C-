#include <iostream>

using namespace std;


void error(string func, string s)
{
  cerr << '[' << func << "]: " << s << '\n';
  throw exception();
}



class Money{
public:
  Money()
    :amount(0) { }
  Money(int d, int c);
  long int get_amount() const { return amount; }
private:
  long int amount;
};


Money::Money(int d, int c)
{
  if ((d < 0) || (c < 0)) error("Money", "amount cannot be negative");
  amount = d * 100 + c;
}


istream & operator>>(istream & is, Money & m)
{
  char dollar_sign;
  int dollar;
  char dot;
  int cent;
  is >> dollar_sign >> dollar >> dot >> cent;
  if (dollar_sign != '$') error("input", "missing '$'");
  if ((cent > 100) || (cent < 0)) error("input", "cent cannot be negative and is limited to 2 digits");
  
  m = Money(dollar, cent);
  return is;
}



int main()
{
  try {
    cout << "Input an amount in the format of $n.n:\n";
    Money m;
    cin >> m;
    cout << "Total amount in cents = " << m.get_amount() << '\n';
    return 0;
  } catch(exception & e) {
    cout << e.what() << endl;
    return 1;
  }
}
  
