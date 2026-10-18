/* ------------------------------------------
author: Jason Suits
date: 9/27/2026
------------------------------------------ */

#include "BankAccount.h"
#include <iostream>
#include <limits>

BankAccount::BankAccount() {
    accountNumber = "";
    accountHolderName = "";
    accountBalance = 0.0;
}

BankAccount::BankAccount(const std::string& _accountNumber, const std::string& _accountHolderName, double _startingBalance) {
    accountBalance = (_startingBalance >= 0.0) ? _startingBalance : 0.0;
    accountNumber = _accountNumber;
    accountHolderName = _accountHolderName;
}

// Destructor
BankAccount::~BankAccount() {
    // std::string and double manage their own memory automatically.
    // If we were using raw pointers (such as int* data), we would use cleanup here.
}

// Copy Constructor
BankAccount::BankAccount(const BankAccount& other) {
    accountNumber = other.accountNumber;
    accountHolderName = other.accountHolderName;
    accountBalance = other.accountBalance;
}

// Copy Assignment Operator
BankAccount& BankAccount::operator=(const BankAccount& other) {
    // Protect against self-assignment (e.g., account1 = account1)
    if (this != &other) {
        accountNumber = other.accountNumber;
        accountHolderName = other.accountHolderName;
        accountBalance = other.accountBalance;
    }
    return *this; // Return the newly updated object
}

BankAccount& BankAccount::operator+=(double amount) {
    if (amount > 0) {
        accountBalance += amount;
    }
    return *this; // Return the updated object for chaining
}

BankAccount& BankAccount::operator-=(double amount) {
    if (amount > 0 && amount <= accountBalance) {
        accountBalance -= amount;
    }
    return *this; // Return the updated object for chaining
}


bool BankAccount::deposit(double amount) {
    if (amount> 0)
    {
        accountBalance += amount;
        return true;
    }
    else
    {
        return false;
    }
}

bool BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= accountBalance) {
        accountBalance -= amount;
        return true;
    }
    else
    {
        return false;
    }
}

void BankAccount::setAccountHolderName(const std::string& name) {
    accountHolderName = name;
}

std::string BankAccount::getAccountHolderName() const {
    return accountHolderName;
}

double BankAccount::getAccountBalance() const {
    return accountBalance;
}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}

void BankAccount::printAccount(const BankAccount& account) {
    std::cout << "Account Number: " << account.getAccountNumber() << "\n";
    std::cout << "Account Holder: " << account.getAccountHolderName() << "\n";
    std::cout << "Account Balance: $" << account.getAccountBalance() << "\n";
}

BankAccount* BankAccount::createAccountFromInput() {
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
    return new BankAccount(accNum, name, initialBalance);
}