#include <iostream>
#include "SavingsAccount.h"
#include "PremiumSavings.h"
#include "CurrentAccount.h"
#include "Manager.h"

int main() {
    Manager<Account> manager;

    try {
        manager.add(new SavingsAccount("Sam", 1200, 0.05));
        manager.add(new SavingsAccount("Karen", 800, 0.04));
        manager.add(new PremiumSavings("Kris", 2500, 0.05, 0.02));
        manager.add(new CurrentAccount("Cherry", 600, 300));
        manager.add(new CurrentAccount("Rao", 1500, 500));
        manager.add(new PremiumSavings("Mia", 1800, 0.05, 0.03));
        manager.add(new CurrentAccount("John", 400, 200));
        manager.add(new PremiumSavings("David", 5000, 0.07, 0.04));

        std::cout << "\n--- Initial Accounts ---\n";
        manager.displayAll();

        manager.get(0)->deposit(300);   
        manager.get(1)->deposit(200);   
        manager.get(5)->deposit(500);   
        manager.get(7)->withdraw(100); 
        std::cout << "\n--- After Transactions ---\n";
        manager.displayAll();

        manager.sortByBalance();
        std::cout << "\n--- Sorted by Balance ---\n";
        manager.displayAll();

        auto rich = manager.findIf([](Account* acc) {
            return acc->getBalance() > 2000;
        });

        std::cout << "\n--- First account with balance > 2000 ---\n";
        if (rich) {
            rich->display();
        } else {
            std::cout << "None found\n";
        }

       
        int highCount = 0;
        for (size_t i = 0; i < manager.size(); i++) {
            if (manager.get(i)->getBalance() > 1000)
                highCount++;
        }

        std::cout << "\nTotal accounts with balance > 1000: "
                  << highCount << "\n";

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << '\n';
    }

    return 0;
}