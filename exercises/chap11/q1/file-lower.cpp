#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;



int main()
{
  ifstream inputfile("input.txt");
  ofstream outputfile("output.txt");
  
  while (inputfile.good()) {
    string line;
    getline(inputfile, line);

    for (int i=0; i<line.size(); ++i) {
      char c = tolower(line[i]);
      outputfile << c;
    }
    outputfile << '\n';
  }

  inputfile.close();
  outputfile.close();
  return 0;
}
