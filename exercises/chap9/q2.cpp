#include <string>
#include <vector>
#include <iostream>

using namespace std;



class Name_pairs {
public:
  //Name_pairs(vector<string> n, vector<double> d)
  //  :name(n), age(d) { }
  void read_names();
  void read_ages();
  void print();
private:
  vector<string> name;
  vector<double> age;
};


void Name_pairs::read_names() {
  cout << "Enter names (end by ';'):\n";
  string n;
  cin >> n;
  while (n != ";") {
    name.push_back(n);
    cin >> n;
  }
}


void Name_pairs::read_ages() {
  cout << "Enter ages (end by '-1'):\n";
  double n;
  cin >> n;
  while (n != -1) {
    if (n < 0) {
      cerr << "Negative age";
      throw exception();
    }
    age.push_back(n);
    cin >> n;
  }
}



void Name_pairs::print() {
  for (int i=0; i<name.size(); ++i) {
    cout << '(' << name[i] << ", " << age[i] << ")\n";
  }
}



int main()
{
  try {
    Name_pairs np;
    np.read_names();
    np.read_ages();
    np.print();
    return 0;
  } catch (exception & e) {
    cout << e.what() << endl;
    return 1;
  }
}
