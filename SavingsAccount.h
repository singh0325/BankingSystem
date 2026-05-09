#pragma once
#include "Account.h"

class SavingsAccount : public Account {
protected:
    double interestRate;     // Annual interest rate as decimal (e.g., 0.05 = 5%)

public:
    SavingsAccount(const std::string& name, double balance, double rate);  // Constructor with interest rate

    void applyInterest();          // Adds interest earnings to current balance
    void display() const override; // Shows [Savings] prefix before account details
};
