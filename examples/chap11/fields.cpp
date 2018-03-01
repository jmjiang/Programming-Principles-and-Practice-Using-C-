#include <iostream>
#include <iomanip>

using namespace std;



int main()
{
  int temp = 12345;
  // 12345|12345|   12345|12345|
  cout << temp << '|'
       << setw(4) << temp << '|'
       << setw(8) << temp << '|'
       << temp << "|\n";        // field sizes don't stick

  double temp2 = 1234.5;  
  // 1234.5|1234.5|  1234.5|1234.5|
  // The dot is also counted size 1
  cout << temp2 << '|'
       << setw(4) << temp2 << '|'
       << setw(8) << temp2 << '|'
       << temp2 << "|\n";

  string temp3 = "asdfg";
  // asdfg|asdfg|   asdfg|asdfg|
  cout << temp3 << '|'
       << setw(4) << temp3 << '|'
       << setw(8) << temp3 << '|'
       << temp3 << "|\n";
  return 0;
}
