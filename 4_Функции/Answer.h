#pragma once
#include <iostream>

constexpr double PI = 3.141592653589793;

double area(double w, double h) { return w * h; } // прямоугольник
double area(double r) { return PI * r * r; }      // круг

int main() {
  double w, h, r;
  std::cin >> w >> h >> r;
  std::cout << "Rect = " << area(w, h) << "\n"
            << "Circ = " << area(r) << "\n";
}
