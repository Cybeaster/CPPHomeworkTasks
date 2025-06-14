#pragma once

#include <iostream>
#include <limits>

int main() {
  int arr[10];
  int minV = std::numeric_limits<int>::max();
  int maxV = std::numeric_limits<int>::min();

  for (int i = 0; i < 10; ++i) {
    arr[i] = i * i;
    if (arr[i] < minV)
      minV = arr[i];
    if (arr[i] > maxV)
      maxV = arr[i];
  }
  std::cout << "min=" << minV << "  max=" << maxV << '\n';
}
