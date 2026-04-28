#include "PremiumSavings.h"

PremiumSavings::PremiumSavings(const std::string& name, double balance,
                               double rate, double bonus)
    : SavingsAccount(name, balance, rate), bonusRate(bonus) {}

void PremiumSavings::applyBonus() {
    balance += balance * bonusRate;
}

void PremiumSavings::display() const {
    std::cout << "[Premium Savings] ";
    Account::display();
}