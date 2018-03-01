#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> & nums, string label) {
  for (int i=0; i<nums.size(); ++i) {
    cout << nums[i] << ' ';
  }
  cout << '\n';
}



int main() {
  vector<int> x;
  x.push_back(1);
  print(x, "lala");
}
