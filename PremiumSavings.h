#pragma once
#include "SavingsAccount.h"

class PremiumSavings : public SavingsAccount {
private:
    double bonusRate;

public:
    PremiumSavings(const std::string& name, double balance,
                   double rate, double bonus);

    void applyBonus();
    void display() const override;
};