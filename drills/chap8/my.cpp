#include "my.h"
#include <iostream>
using namespace std;

int foo;     // must be defined in this file because print_foo uses it

void print_foo() {
  cout << foo << '\n';
}



void print(int i) {
  cout << i << '\n';
}
