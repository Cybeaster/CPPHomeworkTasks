#include <iostream>
#include <vector>
#include <list>
#include <string>

// 1) Шаблонная функция filter
template<typename Container, typename Predicate>
Container filter(const Container& input, Predicate pred) {
  Container result;
  for (const auto& elem : input) {
    if (pred(elem)) {
      result.push_back(elem);
    }
  }
  return result;
}

int main() {
  // Пример 1: отфильтровать чётные числа из вектора
  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto evens = filter(nums, [](int x) {
      return x % 2 == 0;
  });
  std::cout << "Чётные числа:\n";
  for (int x : evens) {
    std::cout << x << "\n";
  }

  std::cout << "\n";

  // Пример 2: отфильтровать строки длиной ≥ 5 из списка
  std::list<std::string> words = {
    "apple", "bee", "cherry", "dog", "elephant", "fox"
};
  auto long_words = filter(words, [](const std::string& s) {
      return s.size() >= 5;
  });
  std::cout << "Строки длиной ≥ 5:\n";
  for (const auto& w : long_words) {
    std::cout << w << "\n";
  }

  return 0;
}
