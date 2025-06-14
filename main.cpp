#pragma once

#include <iostream>

int main() {
  double lhs{}, rhs{};
  char op{};
  std::cout << "Введите выражение (<a> <op> <b>): ";
  if (!(std::cin >> lhs >> op >> rhs)) {
    std::cerr << "Ошибка ввода\n";
    return 1;
  }

  switch (op) {
  case '+':
    std::cout << lhs + rhs;
    break;
  case '-':
    std::cout << lhs - rhs;
    break;
  case '*':
    std::cout << lhs * rhs;
    break;
  case '/':
    if (rhs == 0) {
      std::cerr << "Деление на ноль!\n";
      return 2;
    }
    std::cout << lhs / rhs;
    break;
  default:
    std::cerr << "Неизвестная операция\n";
    return 3;
  }
  std::cout << '\n';
}
