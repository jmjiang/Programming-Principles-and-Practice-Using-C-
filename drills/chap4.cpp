#include <iostream>
#include <vector>
using namespace std;

/*
 * returns the index of the minimum element in a double vector
 */
int min_idx(vector<double> v) {
  if (v.size() == 0) {
    cout << "Empty vector.\n";
    exit(1);
  }
  int idx = 0;
  double min = v[0];
  for (int i=1; i<v.size(); ++i) {
    if (v[i] < min) {
      min = v[i];
      idx = i;
    }
  }
  return idx;
}

/*
 * sort the values in a double vector from minimum to maximum
 */
vector<double> sort(vector<double> v) {
  vector<double> result;
  vector<double> v2 = v;
  int idx = 0;
  while (v2.size() != 0) {
    idx = min_idx(v2);
    result.push_back(v2[idx]);
    v2.erase(v2.begin() + idx);
  }
  return result;
}

/*
 * convert a value with unit cm, in, or ft, to a value with unit m
 */
double to_meter(double val, string unit) {
  const double cm_to_m = 0.01;
  const double in_to_cm = 2.54;
  const double ft_to_in = 12;

  const double in_to_m = in_to_cm * cm_to_m;
  const double ft_to_m = ft_to_in * in_to_m;

  double converted = 0.0;

  if (unit == "cm") converted = val * cm_to_m;
  else if (unit == "m") converted = val;
  else if (unit == "in") converted = val * in_to_m;
  else if (unit == "ft") converted = val * ft_to_m;
  else {
    cout << "Wrong unit.\n";
    exit(1);
  }
  return converted;
}

/*
 * return the absolute value of the difference of two doubles
 */
double difference(double x, double y) {
  if (x > y) return x - y;
  else return y - x;
}



int main() {
  
  double min = 0;
  double max = 0;
  double sum = 0;
  vector<double> values;

  int counter = 0;
  double i = 0;
  string unit = " ";
  double converted_i = 0;

  const double small = 0.01;

  cout << "Enter a number followed by a unit (cm, m, in, or ft):\n";
  while (cin >> i >> unit) {
    if (unit == "cm" || unit == "m" || unit == "in" || unit == "ft") {
      cout << i << unit << "  ";
      // To keep track of the smallest (min) and the largest (max)
      if (counter == 0) {
        cout << '\n';
        min = i;
        max = i;
      } else {
        if (i < min) {
          min = i;
          cout << "the smallest so far\n";
        } else if (i > max) {
          max = i;
          cout << "the largest so far\n";
        } else {
          cout << '\n';
        }
      }
      // To keep track of the number of values
      ++counter;
      // To keep track of the sum and all values entered so far: converted to meters
      converted_i = to_meter(i, unit);
      sum += converted_i;
      values.push_back(converted_i);
    } else {
      cout << "Wrong unit. Value rejected.\n";
    }
  }
  cout << "the smallest = " << min << '\n';
  cout << "the largest = " << max << '\n';
  cout << "the number of (valid) values entered = " << counter << '\n';
  cout << "the sum = " << sum << "m\n";
  cout << "the sorted values are (convereted to meters): ";
  vector<double> values_sorted = sort(values);
  for (int j=0; j<values_sorted.size(); ++j) {
    cout << values_sorted[j] << "  ";
  }
  cout << '\n';

  /* 1-5
  while (cin >> i1 >> i2) {
    if (i1 < i2) {
      cout << "the smaller value is: " << i1 << '\n';
      cout << "the larger value is: " << i2 << '\n';
      if (difference(i1, i2) < small) cout << "the numbers are almost equal\n";
    } else if (i1 > i2){
      cout << "the smaller value is: " << i2 << '\n';
      cout << "the larger value is: " << i1 << '\n';
      if (difference(i1, i2) < small) cout << "the numbers are almost equal\n";
    } else {
      cout << "the numbers are equal\n";
    }
  }
  */

  return 0;
}
