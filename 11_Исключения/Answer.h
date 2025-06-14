#include <iostream>
#include <stdexcept>
#include <string>

// 1) Иерархия исключений
struct BankException : std::runtime_error {
  using runtime_error::runtime_error;
};
struct InvalidAmount : BankException {
  using BankException::BankException;
};
struct InsufficientFunds : BankException {
  using BankException::BankException;
};
struct InvalidInitialBalance : BankException {
  using BankException::BankException;
};

// 2) Класс BankAccount
class BankAccount {
public:
  explicit BankAccount(double initial) : balance_(initial) {
    if (initial < 0)
      throw InvalidInitialBalance("Initial balance cannot be negative: " +
                                  std::to_string(initial));
  }

  void deposit(double amount) {
    if (amount <= 0)
      throw InvalidAmount("Deposit must be positive: " +
                          std::to_string(amount));
    balance_ += amount;
  }

  void withdraw(double amount) {
    if (amount <= 0)
      throw InvalidAmount("Withdrawal must be positive: " +
                          std::to_string(amount));
    if (amount > balance_)
      throw InsufficientFunds("Insufficient funds: requested " +
                              std::to_string(amount) + ", available " +
                              std::to_string(balance_));
    balance_ -= amount;
  }

  double getBalance() const noexcept { return balance_; }

private:
  double balance_;
};

// 3) main()
int main() {
  // Попытка создать счёт с отрицательным стартовым балансом
  try {
    BankAccount bad(-100);
  } catch (const InvalidInitialBalance &e) {
    std::cerr << "Не удалось создать счёт: " << e.what() << "\n";
  }

  // Создаём корректный счёт
  BankAccount account(50.0);
  try {
    account.deposit(100.0);  // OK: balance = 150
    account.withdraw(50.0);  // OK: balance = 100
    account.withdraw(200.0); // Ошибка: больше чем есть
  } catch (const InsufficientFunds &e) {
    std::cerr << "Ошибка снятия: " << e.what() << "\n";
  } catch (const InvalidAmount &e) {
    std::cerr << "Неверная сумма: " << e.what() << "\n";
  } catch (const BankException &e) {
    std::cerr << "Банковская ошибка: " << e.what() << "\n";
  }

  std::cout << "Итоговый баланс: " << account.getBalance() << "\n";
  return 0;
}
