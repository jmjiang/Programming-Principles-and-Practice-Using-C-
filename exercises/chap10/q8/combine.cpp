#include <fstream>
#include <iostream>

using namespace std;


void combine(string f1, string f2, string of)
{
  ifstream ifs1(f1);
  if (!ifs1) {
    cerr << "Cannot open file " << f1 << endl;
    throw exception();
  }

  ifstream ifs2(f2);
  if (!ifs2) {
    cerr << "Cannot open file " << f2 << endl;
    throw exception();
  }

  ofstream ofs(of);
  if (!ofs) {
    cerr << "Cannot open file " << of << endl;
    throw exception();
  }
  
  string s;
  while (getline(ifs1, s)) {
    ofs << s << '\n';
  }

  while (getline(ifs2, s)) {
    ofs << s << '\n';
  }

  ifs1.close();
  ifs2.close();
  ofs.close();
}


int main()
{
  try {
    string f1 = "file1.txt";
    string f2 = "file2.txt";
    string output = "outfile.txt";
    combine(f1, f2, output);
    return 0;
  } catch (exception & e) {
    return 1;
  }
}
