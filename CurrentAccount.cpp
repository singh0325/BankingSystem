#include "CurrentAccount.h"
#include <stdexcept>

// Constructs current account with overdraft limit in addition to base account
CurrentAccount::CurrentAccount(const std::string& name, double balance, double limit)
    : Account(name, balance), overdraftLimit(limit) {}

// Allows withdrawal beyond balance up to overdraft limit
void CurrentAccount::withdraw(double amount) {
    if (amount > balance + overdraftLimit) {
        throw std::runtime_error("Overdraft limit exceeded.");
    }
    balance -= amount;
}

// Overrides display to label account type before showing base details
void CurrentAccount::display() const {
    std::cout << "[Current] ";
    Account::display();
}
