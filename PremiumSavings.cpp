#include "PremiumSavings.h"

// Constructs premium savings account with base rate and additional bonus rate
PremiumSavings::PremiumSavings(const std::string& name, double balance,
                               double rate, double bonus)
    : SavingsAccount(name, balance, rate), bonusRate(bonus) {}

// Adds bonus interest to current balance without affecting regular interest
void PremiumSavings::applyBonus() {
    balance += balance * bonusRate;
}

// Overrides display to identify account as Premium Savings before showing details
void PremiumSavings::display() const {
    std::cout << "[Premium Savings] ";
    Account::display();
}
