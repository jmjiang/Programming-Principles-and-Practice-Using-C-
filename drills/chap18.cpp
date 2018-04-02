#include <iostream>
#include <vector>

using namespace std;



int factorial(int n)
{
  if (n == 0) return 1;
  return n * factorial(n-1);
}



// array drill
int ga[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(int arr[], int n)
{
  int n2 = 10;
  int la[n2];
  for (int i=0; i<n; ++i) {
    la[i] = arr[i];
  }
  cout << "la = ";
  for (int i=0; i<n2; ++i) {
    cout << la[i] << " ";
  }
  cout << endl;

  int* p = new int[n];
  for (int i=0; i<n; ++i) {
    p[i] = arr[i];
  }
  cout << "p = ";
  for (int i=0; i<n; ++i) {
    cout << p[i] << " ";
  }
  cout << endl;

  delete[] p;
}


// vector drill
vector<int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f2(vector<int> v)
{
  vector<int> lv(gv.size());
  for (int i=0; i<gv.size(); ++i) {
    lv[i] = gv[i];
  }
  cout << "lv = ";
  for (int i : lv) cout << i << " ";
  cout << endl;

  vector<int> lv2(v);
  cout << "lv2 = ";
  for (int i : lv2) cout << i << " ";
  cout << endl;

}



int main()
{
  cout << "ARRAY DRILL" << endl;
  cout << "----- f(ga) -----" << endl;
  f(ga, 10);
  cout << endl;

  int aa[10];
  for (int i=0; i<10; ++i) {
    aa[i] = factorial(i+1);
  }
  cout << "----- f(aa) -----" << endl;
  f(aa, 10);
  cout << endl;
    
  cout << "VEVTOR DRILL" << endl;
  cout << "----- f2(gv) -----" << endl;
  f2(gv);

  vector<int> vv(10);
  for (int i=0; i<10; ++i) {
    vv[i] = factorial(i+1);
  }
  cout << "----- f2(aa) -----" << endl;
  f2(vv);
  cout << endl;
  return 0;
}
