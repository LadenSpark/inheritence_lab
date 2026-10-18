/* --- CheckingAccount.cpp --- */

/* ------------------------------------------
author: Laden
date: 10/17/2026
------------------------------------------ */

#include "BankAccount.h"
#include "CheckingAccount.h"
#include <iostream>
#include <limits>

CheckingAccount::CheckingAccount() : BankAccount(), transactionFee(0.0) {}

CheckingAccount::~CheckingAccount() {
    // Destructor
}

CheckingAccount::CheckingAccount(const std::string& _accountNumber, const std::string& _accountHolderName, double _startingBalance, double _transactionFee)
    : BankAccount(_accountNumber, _accountHolderName, _startingBalance),
      transactionFee((_transactionFee >= 0.0) ? _transactionFee : 0.0) {

      }

CheckingAccount* CheckingAccount::createCheckingAccountFromInput() {
    std::string accNum, name;
    double initialBalance, fee;

    std::cout << "Enter account number: ";
    std::cin >> accNum;

    // Clear the leftover newline from the buffer so getline works properly
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter account holder name: ";
    std::getline(std::cin, name);

    std::cout << "Enter initial balance: $";
    std::cin >> initialBalance;

    std::cout << "Enter transaction fee: $";
    std::cin >> fee;

    // Uses your parameterized constructor to build and return the new object
    return new CheckingAccount(accNum, name, initialBalance, fee);
}

bool CheckingAccount::withdraw(double amount) {
    // Check if the withdrawal amount is valid and if there are sufficient funds including the transaction fee
    if (amount > 0 && (amount + transactionFee) <= getAccountBalance()) {
        // Call the base class withdraw method to deduct the amount
        BankAccount::withdraw(amount + transactionFee);
        return true;
    }
    return false; // Withdrawal failed due to insufficient funds or invalid amount
}

double CheckingAccount::getTransactionFee() const {
    return transactionFee;
}
