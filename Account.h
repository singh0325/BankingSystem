#pragma once
#include <iostream>
#include <string>

class Account {
protected:
    std::string name;
    double balance;

public:
    Account(const std::string& name, double balance);
    virtual ~Account() = default;

    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual void display() const;

    double getBalance() const;
};