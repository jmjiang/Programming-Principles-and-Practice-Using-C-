
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void error(string s) {
    cerr << s << '\n';
    throw exception();
}

void error(string s1, string s2) {
    cerr << s1 << s2 << '\n';
    throw exception();
}

struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string s) :kind(ch), name(s) { }
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }     // 0 is false, noon-zero is true

	Token get();
	void unget(Token t) { buffer=t; full=true; }

	void ignore(char);
};

const char let = 'L';
const char constant = 'C';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square = 's';
const char power = 'p';

Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
        case quit:
        case print:
        case ',':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
		double val;
		cin >> val;
		return Token(number,val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || (ch == '_'))) s += ch;
			cin.unget();
			if (s == "let") return Token(let);	
                        if (s == "const") return Token(constant);
			if (s == "sqrt") return Token(square);	
			if (s == "pow") return Token(power);	
			return Token(name,s);
		}
		error("Bad token");
                return 0;
	}
}

void Token_stream::ignore(char c)
{
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};



vector<Variable> names;	
vector<Variable> const_names;



double get_value(string s)
{
	for (int i = 0; i < const_names.size(); ++i)
		if (const_names[i].name == s) return const_names[i].value;
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
        return 0;
}



void set_value(string s, double d)
{
    for (int i = 0; i < const_names.size(); ++i) {
        if (const_names[i].name == s) {
            error("set: cannot modify a constant's value");
            return;
        }
    }
    for (int i = 0; i < names.size(); ++i)
        if (names[i].name == s) {
            names[i].value = d;
            return;
        }
    error("set: undefined name ", s);
}



bool is_declared(string s) {
	for (int i = 0; i<const_names.size(); ++i)
		if (const_names[i].name == s) return true;
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}



double expression(Token_stream & ts);

double primary(Token_stream & ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression(ts);
		t = ts.get();
		if (t.kind != ')') error("')' expected");
	}
	case '-':
		return - primary(ts);
	case number:
		return t.value;
	case name:
		return get_value(t.name);
        case square:
        {
                t = ts.get();
                if (t.kind != '(') error("'(' expected");
                double d1 = expression(ts);
                if (d1 < 0) {
                    error("cannot take the square root of a negative number");
                    return 0;
                }
                double d = sqrt(d1);
                t = ts.get();
                if (t.kind != ')') error("')' expected");
                return d;
        }
        case power:
        {
                t = ts.get();
                if (t.kind != '(') error("'(' expected");
                double d1 = expression(ts);
                t = ts.get();
                if (t.kind != ',') error("',' expected");
                double d2 = expression(ts);
                if (d2 != int(d2)) error("the 2nd argument must be an integer");
                t = ts.get();
                if (t.kind != ')') error("')' expected");
                return pow(d1, d2);
        }
	default:
		error("primary expected");
                return 0;
	}
}

double term(Token_stream & ts)
{
	double left = primary(ts);
	Token t = ts.get();
	while(true) {
		switch(t.kind) {
		case '*':
			left *= primary(ts);
                        t = ts.get();
			break;
		case '/':
		{	double d = primary(ts);
			if (d == 0) error("divide by zero");
			left /= d;
                        t = ts.get();
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression(Token_stream & ts)
{
	double left = term(ts);
        Token t = ts.get();
	while(true) {
		switch(t.kind) {
		case '+':
			left += term(ts);
                        t = ts.get();
			break;
		case '-':
			left -= term(ts);
                        t = ts.get();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}


// con indicates if this is for defining a constant variable
void define_name(string var, double val, bool con) {
    if (is_declared(var)) {
      error(var, " variable declared twice");
      return;
    }
    if (con) const_names.push_back(Variable(var, val));
    else names.push_back(Variable(var, val));
}



// con indicates if this is for declaring a constant variable
double declaration(Token_stream & ts, bool con)
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);

        double d = expression(ts);
        define_name(var_name, d, con);
	return d;
}



double statement(Token_stream & ts)
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration(ts, false);
        case constant:
                return declaration(ts, true);
        case name:
        {
                Token t2 = ts.get();
                if (t2.kind == '=') {
                    double d = expression(ts);
                    set_value(t.name, d);
                    return d;
                } else {
                    cin.putback(t2.kind);
                    // these two lines can be deleted, which
                    // will make the program fall through to default.
                    // Included here for clarity.
                    ts.unget(t);
                    return expression(ts);
                }
        }
	default:
		ts.unget(t);
		return expression(ts);
	}
}

void clean_up_mess(Token_stream & ts)
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate(Token_stream & ts)
{
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement(ts) << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess(ts);
	}
}

int main()
{
	try {
                Token_stream ts;
		calculate(ts);
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		// char c;
		// while (cin >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}
}
