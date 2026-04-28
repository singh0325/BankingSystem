#pragma once
#include "Account.h"

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(const std::string& name, double balance, double limit);

    void withdraw(double amount) override;
    void display() const override;
};