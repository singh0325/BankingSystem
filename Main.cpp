#include <iostream>
#include "SavingsAccount.h"
#include "PremiumSavings.h"
#include "CurrentAccount.h"
#include "Manager.h"

int main() {
    Manager<Account> manager;
    int choice;

    do {
        std::cout << "\n1. Add Savings Account"
                  << "\n2. Add Premium Savings"
                  << "\n3. Add Current Account"
                  << "\n4. Deposit"
                  << "\n5. Withdraw"
                  << "\n6. Display All"
                  << "\n7. Sort by Balance"
                  << "\n8. Find Balance > 1000"
                  << "\n0. Exit\n";

        std::cin >> choice;

        try {
            if (choice == 1) {
                std::string name;
                double bal, rate;
                std::cout << "Enter name, balance, interest rate: ";
                std::cin >> name >> bal >> rate;
                manager.add(new SavingsAccount(name, bal, rate));
            }
            else if (choice == 2) {
                std::string name;
                double bal, rate, bonus;
                std::cout << "Enter name, balance, rate, bonus: ";
                std::cin >> name >> bal >> rate >> bonus;
                manager.add(new PremiumSavings(name, bal, rate, bonus));
            }
            else if (choice == 3) {
                std::string name;
                double bal, limit;
                std::cout << "Enter name, balance, overdraft: ";
                std::cin >> name >> bal >> limit;
                manager.add(new CurrentAccount(name, bal, limit));
            }
            else if (choice == 4) {
                size_t i; double amt;
                std::cout << "Index & amount: ";
                std::cin >> i >> amt;
                manager.get(i)->deposit(amt);
            }
            else if (choice == 5) {
                size_t i; double amt;
                std::cout << "Index & amount: ";
                std::cin >> i >> amt;
                manager.get(i)->withdraw(amt);
            }
            else if (choice == 6) {
                manager.displayAll();
            }
            else if (choice == 7) {
                manager.sortByBalance();
                std::cout << "Sorted successfully.\n";
            }
            else if (choice == 8) {
                auto acc = manager.findIf([](Account* a) {
                    return a->getBalance() > 1000;
                });
                if (acc) acc->display();
                else std::cout << "No such account found.\n";
            }

        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << '\n';
        }

    } while (choice != 0);

    return 0;
}