#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> read_ints(string fname)
{
  ifstream ist(fname);
  ist.exceptions(ist.exceptions()|ios_base::badbit);
  if (ist.fail()) {
    ist.clear();
    cerr << "Cannot open file " << fname;
    throw exception();
  }

  vector<int> nums;
  for (int i; ist >> i;) nums.push_back(i);
  return nums;
}

int sum(const vector<int> nums)
{
  int result = 0;
  for (int i=0; i<nums.size(); ++i) result += nums[i];
  return result;
}

int main()
{
  try {
    string filename = "mydata.txt";
    vector<int> numbers = read_ints(filename);
    cout << "The sum = " << sum(numbers) << endl;
    return 0;
  } catch (exception & e) {
    cout << e.what() << endl;
    return 1;
  }
}
