#pragma once
#include "SavingsAccount.h"

class PremiumSavings : public SavingsAccount {
private:
    double bonusRate;     // Additional interest rate on top of base savings rate

public:
    PremiumSavings(const std::string& name, double balance,
                   double rate, double bonus);  // Constructor with base rate and bonus rate

    void applyBonus();            // Adds bonus interest to balance
    void display() const override; // Shows [Premium Savings] prefix before account details
};
