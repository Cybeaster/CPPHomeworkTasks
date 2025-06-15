#pragma once
/*
Создайте иерархию исключений:

struct BankException       : std::runtime_error { using
runtime_error::runtime_error; }; struct InvalidAmount       : BankException {
using BankException::BankException; }; struct InsufficientFunds   :
BankException      { using BankException::BankException; }; struct
InvalidInitialBalance : BankException    { using BankException::BankException;
};


Реализуйте класс BankAccount:

class BankAccount {
public:
  // Конструктор: если initial < 0 → бросать InvalidInitialBalance
  explicit BankAccount(double initial);

  // Положить деньги: если amount <= 0 → бросать InvalidAmount
  void deposit(double amount);

  // Снять деньги:
  //   если amount <= 0 → бросать InvalidAmount;
  //   если amount > balance_ → бросать InsufficientFunds;
  //   иначе уменьшить balance_.
  void withdraw(double amount);

  double getBalance() const noexcept;
private:
  double balance_;
};

В main():

Попытаться создать счёт с отрицательным балансом и поймать исключение.
Создать корректный счёт, затем:

try {
  account.deposit(100);
  account.withdraw(50);
  account.withdraw(200);   // больше чем есть → InsufficientFunds
}
catch (const InsufficientFunds& e) {
  std::cerr << "Ошибка снятия: " << e.what() << "\n";
}
catch (const InvalidAmount& e) {
  std::cerr << "Неверная сумма: " << e.what() << "\n";
}
catch (const BankException& e) {
  std::cerr << "Банковская ошибка: " << e.what() << "\n";
}

В конце вывести итоговый баланс.

*/

int main() {}