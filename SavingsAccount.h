/* --- SavingsAccount.h --- */

/* ------------------------------------------
Author: Laden
Date: 10/17/2026
------------------------------------------ */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H


#include "BankAccount.h"

class SavingsAccount : public BankAccount {
public:
    SavingsAccount();
    ~SavingsAccount();

    SavingsAccount(const std::string& _accountNumber, const std::string& _accountHolderName, double _startingBalance, double _interestRate);

    bool withdraw(double amount) override;
    void calculateInterest(); // Method to apply interest to the account balance
    static SavingsAccount* createSavingsAccountFromInput(); // Static method to create a SavingsAccount from user input
    double getInterestRate() const; // Accessor for interest rate

private:
    double interestRate; // Interest rate for the savings account
};

#endif // SAVINGSACCOUNT_H
