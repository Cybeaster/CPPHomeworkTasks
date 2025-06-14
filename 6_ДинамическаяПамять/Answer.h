
#pragma once
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  std::srand(static_cast<unsigned>(std::time(nullptr)));
  size_t N{};
  std::cout << "N = ";
  std::cin >> N;
  int *data = new int[N];

  long long sum = 0;
  for (size_t i = 0; i < N; ++i) {
    data[i] = std::rand() % 100;
    sum += data[i];
  }
  std::cout << "Average = " << sum / static_cast<double>(N) << '\n';

  std::sort(data, data + N);
  std::cout << "Sorted: ";
  for (size_t i = 0; i < N; ++i)
    std::cout << data[i] << ' ';
  std::cout << '\n';

  delete[] data;
}
