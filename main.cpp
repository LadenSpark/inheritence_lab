/*
 * Name: Jason Suits
 * Date: October 17, 2026
 * Assignment: Inheritance Lab - Bank Account Management System
 * Purpose: Driver program managing a polymorphic collection of BankAccount pointers.
 */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

int findAccount(const std::vector<BankAccount*>& accounts, const std::string& accountNumber) {
    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i]->getAccountNumber() == accountNumber) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main() {
    int userSelection;
    std::vector<BankAccount*> accounts;
    std::string accountNumber;
    double transactionAmount;

    do {
        std::cout << "\nBank Account Management System\n";
        std::cout << "1. Create a new account\n";
        std::cout << "2. Deposit funds\n";
        std::cout << "3. Withdraw funds (Polymorphic)\n";
        std::cout << "4. Display account balance\n";
        std::cout << "5. Apply interest to Savings Accounts\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        
        if (!(std::cin >> userSelection)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (userSelection) {
            case 1: {
                int accountType;
                std::cout << "Select account type:\n";
                std::cout << "1. Base Bank Account\n";
                std::cout << "2. Checking Account\n";
                std::cout << "3. Savings Account\n";
                std::cout << "Enter your choice: ";
                std::cin >> accountType;

                switch (accountType) {
                    case 1: {
                        std::string accNum, name;
                        double initialBalance;
                        std::cout << "Enter account number: ";
                        std::cin >> accNum;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Enter account holder name: ";
                        std::getline(std::cin, name);
                        std::cout << "Enter initial balance: $";
                        std::cin >> initialBalance;
                        accounts.push_back(new BankAccount(accNum, name, initialBalance));
                        std::cout << "Base bank account created successfully.\n";
                        break;
                    }
                    case 2: {
                        accounts.push_back(CheckingAccount::createCheckingAccountFromInput());
                        std::cout << "Checking account created successfully.\n";
                        break;
                    }
                    case 3: {
                        accounts.push_back(SavingsAccount::createSavingsAccountFromInput());
                        std::cout << "Savings account created successfully.\n";
                        break;
                    }
                    default:
                        std::cout << "Invalid account type selection.\n";
                        break;
                }
                break;
            }
            case 2: {
                std::cout << "Enter account number for deposit: ";
                std::cin >> accountNumber;
                int index = findAccount(accounts, accountNumber);
                if (index != -1) {
                    std::cout << "Enter amount to deposit: $";
                    std::cin >> transactionAmount;
                    if (accounts[index]->deposit(transactionAmount)) {
                        std::cout << "Deposit processed. New balance: $" << accounts[index]->getAccountBalance() << "\n";
                    } else {
                        std::cout << "Invalid deposit amount.\n";
                    }
                } else {
                    std::cout << "Account not found.\n";
                }
                break;
            }
            case 3: {
                std::cout << "Enter account number for withdrawal: ";
                std::cin >> accountNumber;
                int index = findAccount(accounts, accountNumber);
                if (index != -1) {
                    std::cout << "Enter amount to withdraw: $";
                    std::cin >> transactionAmount;
                    
                    // Polymorphic dispatch through base class pointer
                    if (accounts[index]->withdraw(transactionAmount)) {
                        std::cout << "Withdrawal processed. New balance: $" << accounts[index]->getAccountBalance() << "\n";
                    } else {
                        std::cout << "Withdrawal failed: insufficient funds (including fees if checking) or invalid amount.\n";
                    }
                } else {
                    std::cout << "Account not found.\n";
                }
                break;
            }
            case 4: {
                std::cout << "Enter account number to display balance: ";
                std::cin >> accountNumber;
                int index = findAccount(accounts, accountNumber);
                if (index != -1) {
                    BankAccount::printAccount(*accounts[index]);
                } else {
                    std::cout << "Account not found.\n";
                }
                break;
            }
            case 5: {
                std::cout << "Calculating interest across savings accounts...\n";
                bool foundSavings = false;
                for (BankAccount* acc : accounts) {
                    SavingsAccount* sAcc = dynamic_cast<SavingsAccount*>(acc);
                    if (sAcc != nullptr) {
                        sAcc->calculateInterest();
                        std::cout << "Interest applied to Account " << sAcc->getAccountNumber()
                                  << ". New balance: $" << sAcc->getAccountBalance() << "\n";
                        foundSavings = true;
                    }
                }
                if (!foundSavings) {
                    std::cout << "No savings accounts found.\n";
                }
                break;
            }
            case 6: {
                std::cout << "Exiting and freeing allocated accounts.\n";
                break;
            }
            default:
                std::cout << "Invalid choice. Please select 1-6.\n";
                break;
        }
    } while (userSelection != 6);

    // Clean up heap memory to avoid leaks
    for (BankAccount* acc : accounts) {
        delete acc;
    }
    accounts.clear();

    return 0;
}