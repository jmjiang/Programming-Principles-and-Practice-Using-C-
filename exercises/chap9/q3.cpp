#include <string>
#include <vector>
#include <iostream>

using namespace std;



class Name_pairs {
public:
  void read_names();
  void read_ages();

  vector<string> get_name() const { return name; }
  vector<double> get_age() const { return age; }
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



// helper function
ostream & operator<<(ostream & os, Name_pairs np) {
  vector<string> names = np.get_name();
  vector<double> ages = np.get_age();
  for (int i=0; i<names.size(); ++i) {
    os << '(' << names[i] << ", " << ages[i] << ")\n";
  }
  return os;
}



int main()
{
  try {
    Name_pairs np;
    np.read_names();
    np.read_ages();
    cout << np;
    return 0;
  } catch (exception & e) {
    cout << e.what() << endl;
    return 1;
  }
}
