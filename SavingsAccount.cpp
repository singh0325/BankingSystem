#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const std::string& name, double balance, double rate)
    : Account(name, balance), interestRate(rate) {}

void SavingsAccount::applyInterest() {
    balance += balance * interestRate;
}

void SavingsAccount::display() const {
    std::cout << "[Savings] ";
    Account::display();
}