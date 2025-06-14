#pragma once

#include <cstring>
#include <iomanip>
#include <iostream>

void reverse(char *s) {
  char *l = s;
  char *r = s + std::strlen(s) - 1;
  while (l < r) {
    std::swap(*l, *r);
    ++l;
    --r;
  }
}

int main() {
  char buf[256];
  std::cin >> std::setw(256) >> buf;
  reverse(buf);
  std::cout << buf << '\n';
}
