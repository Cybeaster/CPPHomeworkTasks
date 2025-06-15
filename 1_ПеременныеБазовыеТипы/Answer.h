#pragma once
#include <iostream>

int main() {

  long long a{}, b{}, c{};
  std::cout << "Введите три целых числа через пробел: ";
  if (!(std::cin >> a >> b >> c)) {
    std::cerr << "Ошибка ввода — это не целое число\n";
    return 1;
  }

  long long sum = a + b + c;
  double average = sum / 3.0;
  long long maxVal = std::max<>({a, b, c});

  std::cout << "Сумма: " << sum << "\n"
            << "Среднее: " << average << "\n"
            << "Максимум: " << maxVal << '\n';
}