#pragma once
#include <iostream>
#include <string>

class Account {
protected:
    std::string name;      // Account holder's full name
    double balance;        // Current account balance

public:
    Account(const std::string& name, double balance);  // Constructor with holder name and initial balance
    virtual ~Account() = default;                      // Virtual destructor for proper cleanup of derived classes

    virtual void deposit(double amount);   // Adds positive amount to balance
    virtual void withdraw(double amount);  // Removes amount if sufficient funds exist
    virtual void display() const;          // Prints account details to console

    double getBalance() const;              // Returns current balance without modification
};
