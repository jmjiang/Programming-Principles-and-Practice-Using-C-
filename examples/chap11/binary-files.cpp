/*
 * The example does not work correctly.
 * The output file misses the last 7 in the input file.
 * But if the input file only has six numbers, the output file is correct.
 *
 * No matter Whether the input file has 6 or 7 numbers, the vector has size 3.
 * But the last value in v differs.
 *
 */


#include <fstream>
#include <iostream>
#include <vector>

using namespace std;



template<class T>
char * as_bytes(T & i)
{
  void * addr = &i;
  return static_cast<char*>(addr);
}


int main()
{
  try {
    string input = "test-binary-input.txt";
    string output = "test-binary-output.txt";

    cout << "TEMP1" << endl;

    ifstream ifs(input, ios_base::binary);
    cout << "TEMP2" << endl;
    if (!ifs) {
      cerr << "Cannot open input file " << input << endl;
      throw exception();
    }
    cout << "TEMP3" << endl;

    ofstream ofs(output, ios_base::binary);
    cout << "TEMP4" << endl;
    if (!ofs) {
      cerr << "Cannot open output file " << output << endl;
      throw exception();
    }
    cout << "TEMP5" << endl;

    vector<int> v;

    // read from binary file
    for (int x; ifs.read(as_bytes(x), sizeof(int)); ) v.push_back(x);
    cout << "TEMP6" << endl;

    // write to binary file
    for (int i; i<v.size(); ++i) {
      cout << "TEMP7" << endl;
      cout << "v[" << i << "] = " << v[i] << endl;
      ofs.write(as_bytes(v[i]), sizeof(int));
    }
    cout << "TEMP8" << endl;

    ofs.close();
    ifs.close();

    // try read it without binary
    string input2 = "test-binary-input2.txt";
    string output2 = "test-binary-output2.txt";

    ifstream ifs2(input2);

    ofstream ofs2(output2, ios_base::out);
    /*
    if (!ofs2) {
      cerr << "Cannot open output file " << output2 << endl;
      throw exception();
    }
    */

    vector<int> v2;
    /*

    for (int x; ifs2 >> x; ) v2.push_back(x);

    for (int i; i<v2.size(); ++i) {
      cout << "v2[" << i << "] = " << v2[i] << endl;
      ofs2 << v2[i];
    }
    */

    ofs2.close();
    ifs2.close();
    return 0;
  } catch (exception & e) {
    cout << e.what() << endl;
    return 1;
  }
}
