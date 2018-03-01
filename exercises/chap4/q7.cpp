#include <iostream>
#include <string>
#include <vector>
using namespace std;

int word2int(string w, vector<string> words) {
  for (int i=0; i<words.size(); ++i) {
    if (w == words[i]) {
      return i;
    }
  }
  cout << "Couldn't find a match.\n";
  exit(1);
}

string int2word(int x, vector<string> words) {
  if (x < words.size()) {
    return words[x];
  } else {
    cout << "Out of range.\n";
    exit(1);
  }
}

int in(string w, vector<string> words) {
  for (int i=0; i<words.size(); ++i) {
    if (w == words[i]) return i;
  }
  return -1;
}

int input2digit(string w, vector<string> num_words, vector<string> num) {
  if (in(w, num_words) != -1) {
    return word2int(w, num_words);
  } else if (in(w, num) != -1) {
    return in(w, num);
  } else {
    return -1;
  }
}

void compute(int x, int y, char op) {
  switch (op) {
    case '+':
      cout << "The sum of " << x << " and " << y << " is " << x + y << ".\n";
      break;
    case '-':
      cout << "The difference of " << x << " and " << y << " is " << x - y << ".\n";
      break;
    case '*':
      cout << "The product of " << x << " and " << y << " is " << x * y << ".\n";
      break;
    case '/':
      cout << "The division of " << x << " and " << y << " is " << x / y << ".\n";
      break;
    default:
      cout << "Unrecognizable operator.\n";
  }
}


int main() {
  vector<string> num_words;
  num_words.push_back("zero");
  num_words.push_back("one");
  num_words.push_back("two");
  num_words.push_back("three");
  num_words.push_back("four");
  num_words.push_back("five");
  num_words.push_back("six");
  num_words.push_back("seven");
  num_words.push_back("eight");
  num_words.push_back("nine");

  vector<string> num;
  num.push_back("0");
  num.push_back("1");
  num.push_back("2");
  num.push_back("3");
  num.push_back("4");
  num.push_back("5");
  num.push_back("6");
  num.push_back("7");
  num.push_back("8");
  num.push_back("9");

  string x_word = " ";
  string y_word = " ";
  char op = ' ';

  cout << "Enter two single digits (0-9 or zero-nine) and an operator (+, -, *, or /):\n";
  cin >> x_word >> y_word >> op;
  int x = input2digit(x_word, num_words, num);
  if (x == -1) {
    cout << "The first input is not a digit.\n";
    exit(1);
  }
  int y = input2digit(y_word, num_words, num);
  if (y == -1) {
    cout << "The second input is not a digit.\n";
    exit(1);
  }

  compute(x, y, op);

  return 0;
}
