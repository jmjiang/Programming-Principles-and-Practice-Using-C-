#include <vector>
#include <iostream>

using namespace std;



double calculate_index (const vector<double> & v1, const vector<double> & v2) {
  if (v1.size() != v2.size()) {
    cerr << "[calculate_index]: size does not match\n";
    throw exception();
    return 0;
  }
  double result = 0;
  double prod = 0;
  for (int i=0; i<v1.size(); ++i) {
    prod = v1[i] * v2[i];
    result += prod;
  }
  return result;
}



int main() {
  try {
    vector<double> price;
    price.push_back(1);
    price.push_back(2);
    price.push_back(3);

    vector<double> weight;
    weight.push_back(1);
    weight.push_back(2);
    weight.push_back(3);

    double index = calculate_index(price, weight);
    cout << index << '\n';

    return 0;
  } catch (exception & e) {
    cout << e.what() << '\n';
    return 1;
  }
}
