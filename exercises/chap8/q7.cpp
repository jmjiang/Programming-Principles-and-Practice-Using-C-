#include <vector>
#include <iostream>
#include <string>

using namespace std;



int find (string s, const vector<string> & v) {
  if (v.size() == 0) {
    cerr << "[find]: empty vector\n";
    throw exception();
    return -1;
  }
  for (int i=0; i<v.size(); ++i) {
    if (s == v[i]) return i;
  }
  return -1;
}



void sort_name (vector<string> & name, vector<double> & age) {
  if (name.size() != age.size()) {
    cerr << "[sort_name]: the size does not match\n";
    throw exception();
  }
  vector<string> name_copy = name;
  sort(name.begin(), name.end());
  vector<double> age_sorted;

  for (int i=0; i<name.size(); ++i) {
    int idx = find(name[i], name_copy);
    age_sorted.push_back(age[idx]);
  }
  age = age_sorted;
}



void print (const vector<string> & name, const vector<double> & age) {
  if (name.size() != age.size()) {
    cerr << "[print]: the size does not match\n";
    throw exception();
  }
  for (int i=0; i<name.size(); ++i) {
    cout << '(' << name[i] << ", " << age[i] << ")\n";
  }
}



int main() {
  try {
    vector<string> name;
    vector<double> age;
    const int count = 5;

    cout << "Enter five names:\n";
    for (int i=0; i<count; ++i) {
      string temp;
      cin >> temp;
      name.push_back(temp);
    }

    cout << "Enter the ages of the fie people:\n";
    for (int i=0; i<count; ++i) {
      double temp;
      cin >> temp;
      age.push_back(temp);
    }

    cout << "Before Sorting:\n";
    print(name, age);

    sort_name(name, age);
    cout << "After Sorting:\n";
    print(name, age);

    return 0;
  } catch (exception & e) {
    cout << e.what() << '\n';
    return 1;
  }
}
