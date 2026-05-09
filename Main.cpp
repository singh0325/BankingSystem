#include <iostream>
#include "SavingsAccount.h"
#include "PremiumSavings.h"
#include "CurrentAccount.h"
#include "Manager.h"

int main() {
    Manager<Account> manager;  // Generic manager storing heterogeneous account types

    try {
        // Preloaded test data for demonstration purposes
        manager.add(new SavingsAccount("Sam", 1200, 0.05));
        manager.add(new SavingsAccount("Karen", 800, 0.04));
        manager.add(new PremiumSavings("Kris", 2500, 0.05, 0.02));
        manager.add(new CurrentAccount("Cherry", 600, 300));

        int choice;

        do {
            // Display interactive menu options
            std::cout << "\n===== BANK MENU =====\n";
            std::cout << "1. Add Savings Account\n";
            std::cout << "2. Add Premium Savings\n";
            std::cout << "3. Add Current Account\n";
            std::cout << "4. Deposit\n";
            std::cout << "5. Withdraw\n";
            std::cout << "6. Display All\n";
            std::cout << "7. Sort by Balance\n";
            std::cout << "8. Find Account > Balance\n";
            std::cout << "9. Count Accounts > 1000\n";
            std::cout << "0. Exit\n";
            std::cout << "Enter choice: ";
            std::cin >> choice;

            if (choice == 1) {  // Create standard savings account
                std::string name;
                double bal, rate;
                std::cout << "Name: "; std::cin >> name;
                std::cout << "Balance: "; std::cin >> bal;
                std::cout << "Interest Rate: "; std::cin >> rate;
                manager.add(new SavingsAccount(name, bal, rate));
            }

            else if (choice == 2) {  // Create premium savings with bonus rate
                std::string name;
                double bal, rate, bonus;
                std::cout << "Name: "; std::cin >> name;
                std::cout << "Balance: "; std::cin >> bal;
                std::cout << "Interest Rate: "; std::cin >> rate;
                std::cout << "Bonus Rate: "; std::cin >> bonus;
                manager.add(new PremiumSavings(name, bal, rate, bonus));
            }

            else if (choice == 3) {  // Create current account with overdraft
                std::string name;
                double bal, limit;
                std::cout << "Name: "; std::cin >> name;
                std::cout << "Balance: "; std::cin >> bal;
                std::cout << "Overdraft Limit: "; std::cin >> limit;
                manager.add(new CurrentAccount(name, bal, limit));
            }

            else if (choice == 4) {  // Deposit money by account index
                int index;
                double amount;
                std::cout << "Account index: "; std::cin >> index;
                std::cout << "Amount: "; std::cin >> amount;
                manager.get(index)->deposit(amount);
            }

            else if (choice == 5) {  // Withdraw money by account index
                int index;
                double amount;
                std::cout << "Account index: "; std::cin >> index;
                std::cout << "Amount: "; std::cin >> amount;
                manager.get(index)->withdraw(amount);
            }

            else if (choice == 6) {  // Show all accounts with details
                manager.displayAll();
            }

            else if (choice == 7) {  // Sort accounts ascending by balance
                manager.sortByBalance();
                std::cout << "Sorted successfully.\n";
            }

            else if (choice == 8) {  // Locate first account exceeding threshold
                double threshold;
                std::cout << "Enter balance threshold: ";
                std::cin >> threshold;

                auto acc = manager.findIf([&](Account* a) {
                    return a->getBalance() > threshold;
                });

                if (acc) acc->display();
                else std::cout << "No account found.\n";
            }

            else if (choice == 9) {  // Count accounts above 1000 balance
                int count = 0;
                for (size_t i = 0; i < manager.size(); i++) {
                    if (manager.get(i)->getBalance() > 1000)
                        count++;
                }
                std::cout << "Accounts > 1000: " << count << "\n";
            }

        } while (choice != 0);

    } catch (const std::exception& e) {  // Handle any runtime errors gracefully
        std::cout << "Error: " << e.what() << '\n';
    }

    return 0;
}
