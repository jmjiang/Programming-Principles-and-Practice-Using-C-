#include <iostream>
#include <vector>

using namespace std;



void fibonacci(int x, int y, vector<int> & fibs, int len) {
  if (fibs.size() != 0) {
    cerr << "The input vector must be empty.\n";
    throw exception();
  }
  if (len < 0) {
    cerr << "The number of fibonacci numbers to compute must be >= 0\n";
    throw exception();
  }
  if (len >= 1) fibs.push_back(x);
  if (len >= 2) fibs.push_back(y);
  if (len >= 3) {
    for (int i=0; i<len-2; ++i) {
      fibs.push_back( fibs[i] + fibs[i+1] );
    }
  }
}



void print(vector<int> & nums, string label) {
  for (int i=0; i<nums.size(); ++i) {
    cout << nums[i] << ' ';
  }
  cout << '\n';
}



int main() {
  try {
    vector<int> x;
    fibonacci(1, 2, x, 100);
    print(x, "lala");
    return 0;
  } catch (exception & e) {
    cout << e.what() << '\n';
    return 1;
  }
}
