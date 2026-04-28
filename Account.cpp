#include "Account.h"
#include <stdexcept>

Account::Account(const std::string& name, double balance)
    : name(name), balance(balance) {}

void Account::deposit(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Deposit must be positive.");
    }
    balance += amount;
}

void Account::withdraw(double amount) {
    if (amount > balance) {
        throw std::runtime_error("Insufficient balance.");
    }
    balance -= amount;
}

void Account::display() const {
    std::cout << "Name: " << name
              << ", Balance: " << balance << '\n';
}

double Account::getBalance() const {
    return balance;
}