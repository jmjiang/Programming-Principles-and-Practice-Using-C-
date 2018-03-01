
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
 * returns the minimum element in a double vector
 */
int min(vector<double> v) {
  if (v.size() == 0) {
    cout << "Empty vector.\n";
    exit(1);
  }
  double result = v[0];
  for (int i=1; i<v.size(); ++i) {
    if (v[i] < result ) {
      result = v[i];
    }
  }
  return result;
}

/*
 * returns the maximum element in a double vector
 */
int max(vector<double> v) {
  if (v.size() == 0) {
    cout << "Empty vector.\n";
    exit(1);
  }
  double result = v[0];
  for (int i=1; i<v.size(); ++i) {
    if (v[i] > result) {
      result = v[i];
    }
  }
  return result;
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
 * return the median of a vector of doubles
 */
double median(vector<double> v) {
  vector<double> v2 = sort(v);
  int mid_idx = v.size() / 2;
  if (v.size() % 2 == 0) return (v2[mid_idx - 1] + v2[mid_idx]) / 2;
  else return v2[mid_idx];
}

/*
 * compute the sum of the doubles in a vector
 */
double sum(vector<double> v) {
  double result = 0;
  for (int i=0; i<v.size(); ++i) {
    result += v[i];
  }
  return result;
}

int main() {
  vector<double> temps;
  for (double temp; cin >> temp;) {
    temps.push_back(temp);
  }
  cout << "The median = " << median(temps) << '\n';
  cout << "The sum = " << sum(temps) << '\n';
  cout << "The min = " << min(temps) << '\n';
  cout << "The max = " << max(temps) << '\n';
  cout << "The mean = " << sum(temps) / temps.size() << '\n';

  return 0;
}














