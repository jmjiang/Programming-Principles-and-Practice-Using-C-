#include <iostream>

using namespace std;



int main()
{
  cout << "----- P381 -----\n";
  cout << 1234 << "\t(decimal)\n"            // 1234
       << hex << 1234 << "\t(hexadecimal)\n" // 4d2
       << oct << 1234 << "\t(octal)\n";      // 2322
  cout << 1234 << '\n';                      // still 2322
  cout << '\n';
  
  cout << "----- My Question on P382 -----\n";
  cout << "Enter 2322 (stored as a decimal):\n";
  int i = 0;
  cin >> i;   // cin and cout work separately. So the 2322 is store as a decimal in i
  cout << "It is " << i << " in octal\n";    // Since we had <<oct before, this is is output in octal

  cout << "Enter 2322 again (stored as an octal this time):\n";
  cin >> oct >> i;   // now 2322 is stored as an octal in i
  cout << "It is " << dec << i << " in decimal\n";
  cout << '\n';

  cout << "----- P382 below try this -----\n";
  cout << dec << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';
  cout << showbase;
  cout << dec << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';
  cout << '\n';

  cout << "----- P383 -----\n";
  // output 1234 1234 1234
  cout << dec << 1234 << '\t' << 0x4d2 << '\t' << 02322 << '\n';



  return 0;
}
