#pragma once

#include <iomanip>
#include <iostream>

int main() {
  const int N = 10;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j)
      std::cout << std::setw(4) << i * j << ' ';
    std::cout << '\n';
  }
}
