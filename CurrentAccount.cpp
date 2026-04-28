#include "CurrentAccount.h"
#include <stdexcept>

CurrentAccount::CurrentAccount(const std::string& name, double balance, double limit)
    : Account(name, balance), overdraftLimit(limit) {}

void CurrentAccount::withdraw(double amount) {
    if (amount > balance + overdraftLimit) {
        throw std::runtime_error("Overdraft limit exceeded.");
    }
    balance -= amount;
}

void CurrentAccount::display() const {
    std::cout << "[Current] ";
    Account::display();
}