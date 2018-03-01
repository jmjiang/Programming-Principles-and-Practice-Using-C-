
/*
 * Added a function error to mimic the error function in the book.
 */

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------------------------------

const char number = '8';
const char quit = 'q';
const char print = ';';
const char name = 'a';
const char let = 'L';
const string declkey = "let";
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
    string name;
    Token(char ch)    // make a Token from a char
        :kind(ch) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
    Token(char ch, string n)
        :kind(ch), name(n) { }
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
    case '=':
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
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
            cin.putback(ch);
            if (s == declkey) return Token(let);
            return Token(name, s);
        }
        cout << "[get]: ch = " << ch << '\n';
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

class Variable {
public:
    string name;
    double value;
    Variable(string n, double val)     // make a Token from a char and a double
        :name(n), value(val) { }
};

vector<Variable> var_table;



double get_value(string s) {
    for (int i=0; i<var_table.size(); ++i) {
        Variable v = var_table[i];
        if (v.name == s) return v.value;
    }
    error("get_value: undefined variable");
    return 0;
}



void set_value(string s, double d) {
    for (int i=0; i<var_table.size(); ++i) {
        Variable v = var_table[i];
        if (v.name == s) {
            v.value = d;
            return;
        }
    }
    error("set_value: undefined variable");
}



bool is_declared(string var) {
    for (int i=0; i<var_table.size(); ++i) {
        Variable v = var_table[i];
        if (v.name == var) return true;
    }
    return false;
}




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
    case name:
        return get_value(t.name);
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



void define_name(string var, double val) {
    if (is_declared(var)) error("variable declared twice");
    var_table.push_back(Variable(var, val));
}



double declaration() {
    Token t = ts.get();
    if (t.kind != name) error ("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error ("= missing in declaration");

    double d = expression();
    define_name(var_name, d);
    return d;
}


double statement() {
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();
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
            cout << result << statement() << '\n';
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
