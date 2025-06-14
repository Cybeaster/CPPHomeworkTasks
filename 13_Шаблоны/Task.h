#pragma once
/*
1.Реализуйте функцию-шаблон
  template<typename Container, typename Predicate>
  Container filter(const Container& input, Predicate pred);

Которая:
  - Принимает любой стандартный контейнер input (например, std::vector, std::list) и вызываемый объект pred (функцию, функтор или лямбду).
  - Создаёт новый контейнер того же типа, в который копирует лишь те элементы из input, для которых pred(element) возвращает true.


2. В main() продемонстрируйте работу filter на двух примерах:

  Отфильтровать из std::vector<int> только чётные числа.
  Отфильтровать из std::list<std::string> только строки длиной ≥ 5 символов.


3.Выведите результаты на экран, по одному элементу в строке.
*/


int main() {}