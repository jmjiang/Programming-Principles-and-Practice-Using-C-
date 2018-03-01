
/*
 * Added a function error to mimic the error function in the book.
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//------------------------------------------------------------------------------

const char number = '8';
const char quit = 'q';
const char print = ';';
const string result = " = ";
const string prompt = "> ";



void error(string s) {
    cerr << s << '\n';
    throw exception();
}



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
    void ignore(char c);
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};


//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) {
      error("putback() into a full buffer");
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
    case print:
    case quit:
    case '(': case ')': case '+': case '-': case '*': case '/': case '%':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token(number, val);
        }
    default:
        error("Bad token");
        return Token(ch);
    }
}

/* ignore all the input characters up to and including c */
void Token_stream::ignore(char c) {     // c represents the kind of Token
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;
    char ch = 0;
    while (cin >> ch) {
        if (ch == c) return;
    }
}

    

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

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
              error("')' expected");
            }
            return d;
        }
    case number:
        return t.value;  // return the number's value
    case '-':
        return primary() * (-1);
    case '+':
        return primary();
    default:
        error("primary expected");
        return 0;
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
                  error("divide by zero");
                }
                left /= d; 
                t = ts.get();
                break;
            }
        case '%':
            {
                double d = primary();
                if (d == 0) {
                    error("divide by zero");
                }
                left = fmod(left, d);
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



void clean_up_mess() {
  ts.ignore(print);
}



void calculate() {
    while (cin) {
        try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t = ts.get();
            if (t.kind == quit) return;    // interesting: void functions can use return
            ts.putback(t);
            cout << result << expression() << '\n';
        }
        catch (exception & e) {
            cerr << e.what() << '\n';
            clean_up_mess();
        }
    }
}

//------------------------------------------------------------------------------

int main() {
  try
  {
      calculate();
      return 0;
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
