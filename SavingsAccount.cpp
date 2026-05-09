#include "SavingsAccount.h"

// Constructs savings account with base account details and interest rate
SavingsAccount::SavingsAccount(const std::string& name, double balance, double rate)
    : Account(name, balance), interestRate(rate) {}

// Adds interest earnings to current balance based on stored interest rate
void SavingsAccount::applyInterest() {
    balance += balance * interestRate;
}

// Overrides display to label account as Savings before showing base details
void SavingsAccount::display() const {
    std::cout << "[Savings] ";
    Account::display();
}
