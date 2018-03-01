#include <iostream>
using namespace std;



/*
 * The class of Token
 */
class Token {
  public:
    char kind;
    double value;
    Token();
    Token(char, double);
};

Token::Token () {
  kind = 'd';
  value = 0.0;
}

Token::Token (char ch, double v) {
  kind = ch;
  value = v;
}



/*
 * The class of Token_stream
 */
class Token_stream {
  public:
    Token_stream();
    Token get();
    void putback(Token);
  private:
    bool full;
    Token buffer;
};

Token_stream::Token_stream () {
  full = false;
  buffer = Token();
}

Token Token_stream::get () {
  if (full) {
    cout << "ts is full\n";
    full = false;
    return buffer;
  }
  cout << "buffer kind = " << buffer.kind << '\n';
  cout << "buffer value = " << buffer.value << '\n';
  char ch;
  cin >> ch;
  switch (ch) {
    case ';': return Token(ch, 0.0);
    //case 'q':
    case '(': case ')': case '+': case '-': case '*': case '/':
      return Token(ch, 0.0);
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9': {
      cin.putback(ch);
      double val;
      cin >> val;
      cout << "read val = " << val << '\n';
      return Token('8', val);
    }
    default:
      cerr << "Bad token\n";
      exit(1);
  }
}

void Token_stream::putback(Token t) {
  if (full) {
    cerr << "putback() into a full buffer\n";
    exit(1);
  }
  // Not sure why the following changes did not actually take effect
  buffer = t;
  full = true;
}



Token_stream ts;   // global variable



double expression();     // Need to be declared before primary because primary uses it

double term();

double primary() {
  Token t = ts.get();
  cout << "t.kind in primary() = " << t.kind << '\n';
  cout << "t.value in primary() = " << t.value << '\n';
  switch (t.kind) {
    case '(': {
      double d = expression();
      t = ts.get();
      if (t.kind != ')') {
        cerr << "')' expected\n";
        exit(1);
      }
      return d;
    }
    case '8':
      cout << "primary returns " << t.value << '\n';
      return t.value;
    default:
      cerr << "primary expected\n";
      exit(1);
  }
}

double term() {
  double left = primary();
  Token t = ts.get();
  cout << "t.kind in term() = " << t.kind << '\n';
  cout << "t.value in term() = " << t.value << '\n';
  while (true) {
    switch (t.kind) {
      case '*':
        left *= primary();
        t = ts.get();
        break;
      case '/': {
        double d = primary();
        if (d == 0) {
          cerr << "divide by zero\n";
          exit(1);
        }
        left /= d;
        t = ts.get();
        break;
      }
      default:
        cout << "PUTBACK\n";
        ts.putback(t);
        return left;
    }
  }
}

double expression() {
  double left = term();
  cout << "left in expression() = " << left << '\n';
  Token t = ts.get();
  cout << "t.kind in expression() = " << t.kind << '\n';
  cout << "t.value in expression() = " << t.value << '\n';
  while (true) {
    switch (t.kind) {
      case '+':
        left += term();
        t = ts.get();
        break;
      case '-':
        left -= term();
        t = ts.get();
        break;
      case ';':
        return left;
      default:
        ts.putback(t);
        return left;
    }
  }
}



int main() {
  try {
    while (cin)
      cout << " = " << expression() << '\n';
    return 0;
  } catch (exception& e) {
    cerr << e.what() << '\n';
    return 1;
  } catch (...) {
    cerr << "exception \n";
    return 2;
  }
}
