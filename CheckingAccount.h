/* --- CheckingAccount.h --- */

/* ------------------------------------------
Author: Laden
Date: 10/17/2026
------------------------------------------ */

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

class CheckingAccount : public BankAccount {
public:
    CheckingAccount();
    ~CheckingAccount();

    CheckingAccount(const std::string& _accountNumber, const std::string& _accountHolderName, double _startingBalance, double _transactionFee);

    static CheckingAccount* createCheckingAccountFromInput(); // Static method to create a CheckingAccount from user input

    double getTransactionFee() const;

    bool withdraw(double amount) override;

private:
    double transactionFee; // Fee for each transaction

};

#endif // CHECKINGACCOUNT_H
