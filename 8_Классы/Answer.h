#pragma once

#include <iostream>
#include <numeric>

class Fraction {
  long long num_, den_;

public:
  Fraction(long long n = 0, long long d = 1) {
    if (d == 0)
      throw std::invalid_argument("denominator 0");
    if (d < 0) {
      n = -n;
      d = -d;
    }
    long long g = std::gcd(n, d);
    num_ = n / g;
    den_ = d / g;
  }
  double value() const { return static_cast<double>(num_) / den_; }
  friend std::ostream &operator<<(std::ostream &os, const Fraction &f) {
    return os << f.num_ << '/' << f.den_;
  }
};

int main() {
  Fraction f(-2, -8); // 1/4
  std::cout << f << " = " << f.value() << "\n";
}
