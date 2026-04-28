#pragma once
#include "Account.h"

class SavingsAccount : public Account {
protected:
    double interestRate;

public:
    SavingsAccount(const std::string& name, double balance, double rate);

    void applyInterest();
    void display() const override;
};