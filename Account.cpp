#include "Account.h"
#include <stdexcept>

// Initializes account with holder name and starting balance
Account::Account(const std::string& name, double balance)
    : name(name), balance(balance) {}

// Adds funds after validating positive deposit amount
void Account::deposit(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Deposit must be positive.");
    }
    balance += amount;
}

// Removes funds only if sufficient balance exists
void Account::withdraw(double amount) {
    if (amount > balance) {
        throw std::runtime_error("Insufficient balance.");
    }
    balance -= amount;
}

// Outputs account details to standard output
void Account::display() const {
    std::cout << "Name: " << name
              << ", Balance: " << balance << '\n';
}

// Returns current account balance without modification
double Account::getBalance() const {
    return balance;
}
