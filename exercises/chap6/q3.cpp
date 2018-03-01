
#include <iostream>
using namespace std;

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream()             // make a Token_stream that reads from cin
        :full(false), buffer(0) { } 
    Token get();              // get a Token 
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};


//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) {
      cerr << "putback() into a full buffer\n";
      exit(1);
    }
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    } 

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(': case ')': case '{': case '}': case '+': case '-': case '*': case '/': 
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
    case '!':
        return Token(ch);
    default:
        cerr << "Bad token\n";
        exit(1);
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------
int factorial(int n) {
    if (n == 0) return 1;
    int result = 1;
    for (int i=1; i<=n; ++i) {
      result *= i;
    }
    return result;
}

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') {
              cerr << "')' expected\n";
              exit(1);
            }
            return d;
        }
    case '{':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != '}') {
              cerr << "'}' expected\n";
              exit(1);
            }
            return d;
        }
    case '8':            // we use '8' to represent a number
        {
            Token t2 = ts.get();
            if (t2.kind == '!') {
                int val_int = int(t.value);
                if (val_int == t.value) {
                    return factorial(t.value);
                } else {
                    cerr << "Factorial can only be applied on integers.\n";
                    exit(1);
                }
            } else {
              ts.putback(t2);
              return t.value;
            }
        }
    default:
        cerr << "primary expected\n";
        exit(1);
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {    
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
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left += term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main() {
  cout << "Welcome to our simple calculator.\n";
  cout << "Please enter expressions using floating-point numbers.\n";
  try
  {
      while (cin) {

          double val = expression();

          Token t = ts.get();

          if (t.kind == 'x') break; // 'x' for quit
          if (t.kind == '=')        // '=' for "print now"
              cout << val << '\n';
          else
              ts.putback(t);
      }
  }
  catch (exception& e) {
      cerr << "error: " << e.what() << '\n'; 
      return 1;
  }
  catch (...) {
      cerr << "Oops: unknown exception!\n"; 
      return 2;
  }
}

//------------------------------------------------------------------------------
