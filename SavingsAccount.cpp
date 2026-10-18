/* --- SavingsAccount.cpp --- */

/* ------------------------------------------
author: Laden
date: 10/17/2026
------------------------------------------ */

#include "SavingsAccount.h"
#include <iostream>
#include <limits>

SavingsAccount::SavingsAccount() : BankAccount(), interestRate(0.0) {
    // Constructor
}

SavingsAccount::~SavingsAccount() {
    // Destructor
}

SavingsAccount::SavingsAccount(const std::string& _accountNumber, const std::string& _accountHolderName, double _startingBalance, double _interestRate)
    : BankAccount(_accountNumber, _accountHolderName, _startingBalance), 
        interestRate((_interestRate >= 0.0) ? _interestRate : 0.0) {
        // Constructor
    }

void SavingsAccount::calculateInterest() {
    double interest = getAccountBalance() * interestRate;
    BankAccount::deposit(interest);
}

SavingsAccount* SavingsAccount::createSavingsAccountFromInput() {
    std::string accNum, name;
    double initialBalance;

    std::cout << "Enter account number: ";
    std::cin >> accNum;
    
    // Clear the leftover newline from the buffer so getline works properly
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter account holder name: ";
    std::getline(std::cin, name);

    std::cout << "Enter initial balance: $";
    std::cin >> initialBalance;

    // Uses your parameterized constructor to build and return the new object
    return new SavingsAccount(accNum, name, initialBalance, 0.0);
}
bool SavingsAccount::withdraw(double amount) {
    // Check if the withdrawal amount is valid and if there are sufficient funds
    if (amount > 0 && amount <= getAccountBalance()) {
        // Call the base class withdraw method to deduct the amount
        BankAccount::withdraw(amount);
        return true;
    }
    return false; // Withdrawal failed due to insufficient funds or invalid amount
}

double SavingsAccount::getInterestRate() const {
    return interestRate;
}
