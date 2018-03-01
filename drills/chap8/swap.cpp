#include <iostream>
using namespace std;



void swap_v (int a, int b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}



void swap_r (int& a, int& b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}


/*
void swap_cr (const int& a, const int& b) {
  int temp;
  temp = a;
  a = b;    // ERROR: a and b are const, cannot be modified
  b = temp;
}
*/



int main() {
  cout << "swap_v:\n";

  int x = 7;
  int y = 9;
  swap_v(x, y);
  swap_v(7,9);
  cout << "x = " << x << '\n';
  cout << "y = " << y << '\n';

  const int cx = 7;
  const int cy = 9;
  swap_v(cx, cy);
  swap_v(7.7, 9.9);     // warning: conversion from double to int
  cout << "cx = " << cx << '\n';
  cout << "cy = " << cy << '\n';

  double dx = 7.7;
  double dy = 9.9;
  swap_v(dx, dy);
  swap_v(7.7, 9.9);     // warning
  cout << "dx = " << dx << '\n';
  cout << "dy = " << dy << '\n';


  cout << "swap_r:\n";

  x = 7;
  y = 9;
  swap_r(x, y);
  // swap_r(7,9);          // ERROR
  cout << "x = " << x << '\n';
  cout << "y = " << y << '\n';

  // swap_r(cx, cy);       // ERROR
  // swap_r(7.7, 9.9);     // ERROR
  cout << "cx = " << cx << '\n';
  cout << "cy = " << cy << '\n';

  dx = 7.7;
  dy = 9.9;
  // swap_r(dx, dy);       // ERROR
  // swap_r(7.7, 9.9);     // warning
  cout << "dx = " << dx << '\n';
  cout << "dy = " << dy << '\n';
}
