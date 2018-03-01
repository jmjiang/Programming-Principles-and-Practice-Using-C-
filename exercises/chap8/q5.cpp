#include <iostream>
#include <vector>
#include <algorithm>   // swap

using namespace std;

vector<int> reverse_u (vector<int> v) {
  vector<int> result;
  for (int i=v.size()-1; i>=0; --i) {
    result.push_back(v[i]);
  }
  return result;
}



void reverse_c (vector<int> & v) {
  for (int i=0; i<v.size()/2-1; ++i) {
    swap(v[i], v[v.size()-i-1]);
  }
}

int main() {
  vector<int> test;
  test.push_back(1);
  test.push_back(3);
  test.push_back(5);
  test.push_back(7);
  test.push_back(9);

  vector<int> test_reversed = reverse_u(test);
  cout << "test_reversed = ";
  for (int i=0; i<test_reversed.size(); ++i) {
    cout << test_reversed[i] << ' ';
  }
  cout << '\n';

  cout << "test (before reverse_c) = ";
  for (int i=0; i<test.size(); ++i) {
    cout << test[i] << ' ';
  }
  cout << '\n';

  reverse_c(test);
  cout << "test (after reverse_c) = ";
  for (int i=0; i<test.size(); ++i) {
    cout << test[i] << ' ';
  }
  cout << '\n';
}
