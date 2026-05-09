#pragma once
#include "Account.h"

class CurrentAccount : public Account {
private:
    double overdraftLimit;     // Maximum negative balance allowed

public:
    CurrentAccount(const std::string& name, double balance, double limit);  // Constructor with overdraft limit

    void withdraw(double amount) override;  // Allows withdrawal up to balance + overdraft limit
    void display() const override;          // Shows [Current] prefix before account details
};
