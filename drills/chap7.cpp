
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
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.unget();
			if (s == "let") return Token(let);	
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

double get_value(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
        return 0;
}

void set_value(string s, double d)
{
	for (int i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
	}
	case '-':
		return - primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
        case square:
        {
                t = ts.get();
                if (t.kind != '(') error("'(' expected");
                double d1 = expression();
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
                double d1 = expression();
                t = ts.get();
                if (t.kind != ',') error("',' expected");
                double d2 = expression();
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

double term()
{
	double left = primary();
	Token t = ts.get();
	while(true) {
		switch(t.kind) {
		case '*':
			left *= primary();
                        t = ts.get();
			break;
		case '/':
		{	double d = primary();
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

double expression()
{
	double left = term();
        Token t = ts.get();
	while(true) {
		switch(t.kind) {
		case '+':
			left += term();
                        t = ts.get();
			break;
		case '-':
			left -= term();
                        t = ts.get();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}


void define_name(string var, double val) {
    if (is_declared(var)) {
      error(var, " variable declared twice");
      return;
    }
    names.push_back(Variable(var, val));
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error ("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);

	double d = expression();
        define_name(var_name, d);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
{
	try {
                define_name("k", 1000);
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}
}
