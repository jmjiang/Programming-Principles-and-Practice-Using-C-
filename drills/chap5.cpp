#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  try {
    cout << "1:\n";
    cout << "Success!\n";

    cout << "2:\n";
    cout << "Success!\n";

    cout << "3:\n";
    cout << "Success!" << '\n';

    cout << "4:\n";
    cout << "Success!" << '\n';

    cout << "5:\n";
    int res = 7;
    vector<int> v5(10);
    v5[5] = res;
    cout << "Success!\n";

    cout << "6:\n";
    vector<int> v6(10);
    v6[5] = 7;
    if (v6[5] != 7) cout << "Success!\n";
    
    cout << "7:\n";
    bool cond = true;
    if (cond) cout << "Success!\n";
    else cout << "Fail!\n";

    cout << "8:\n";
    bool c = true;
    if (c) cout << "Success!\n";
    else cout << "Fail!\n";
    
    cout << "9:\n";
    string s = "ape";
    c = "fool" > s;
    if (c) cout << "Success!\n";

    cout << "10:\n";
    s = "ape";
    if (s != "fool") cout << "Success!\n";

    cout << "11:\n";
    s = "ape";
    if (s != "fool") cout << "Success!\n";

    cout << "12:\n";
    s = "ape";
    if (s != "fool") cout << "Success!\n";

    cout << "13:\n";
    vector<char> v13(5);
    for (int i=0; i<v13.size(); ++i) cout << "Success!\n";
    
    cout << "14:\n";
    vector<char> v14(5);
    for (int i=0; i<v14.size(); ++i) cout << "Success!\n";
    
    cout << "15:\n";
    s = "Success!\n";
    for (int i=0; i<9; ++i) cout << s[i];
    
    cout << "16:\n";
    if (true) cout << "Success!\n";
    else cout << "Fail!\n";
    
    cout << "17:\n";
    int x = 2000;
    char c17 = x;
    if (x == 2000) cout << "Success!\n";
    
    cout << "18:\n";
    s = "Success!\n";
    for (int i=0; i<9; ++i) cout << s[i];
    
    cout << "19:\n";
    vector<int> v19(5);
    for (int i=0; i < v19.size(); ++i) cout << "Success!\n";
    
    cout << "20:\n";
    int i=0;
    int j = 9;
    while (j<10) ++j;
    if (j>i) cout << "Success!\n";

    cout << "21:\n";
    x = 2;
    double d = 5.0/(x - 1);
    if (d==2*x+1) cout << "Success!\n";
    
    cout << "22:\n";
    s = "Success!\n";
    for (int i=0; i<9; ++i) cout << s[i];

    cout << "23:\n";
    i=0;
    while (i<10) ++i;
    if (j == 10) cout << "Success!\n";

    cout << "24:\n";
    x = 4;
    d = 5.0/(x - 2);
    if (d == x+0.5) cout << "Success!\n";
    
    cout << "25:\n";
    cout << "Success!\n";

    return 0;
  }
  catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
  }
  catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
  }
}
