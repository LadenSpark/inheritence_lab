/* ------------------------------------------
Author: Jason Suits
Date: 9/27/2026
------------------------------------------ */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>

class BankAccount {
public:
    // Prevuious Constructors
    BankAccount();
    BankAccount(const std::string& _accountNumber, const std::string& _accountHolderName, double _startingBalance);

    // New: The rule of five: copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor
    BankAccount(const BankAccount& other); // Copy constructor
    BankAccount& operator=(const BankAccount& other); // Copy assignment operator 
    ~BankAccount(); // Destructor

    // Already existing member accessors and mutators
    void setAccountHolderName(const std::string& name);
    double getAccountBalance() const;
    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;

    // --- Comparison Operators ---
    // 'const' is at the end because comparing accounts shouldn't modify their balances
    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;

    // New: Compound assignment operators for deposit and withdraw
    BankAccount& operator+=(double amount); // Compound assignment operators for deposit and withdraw
    BankAccount& operator-=(double amount); // Compound assignment operators for deposit and withdraw

    // Previous methods
    bool deposit(double amount);
    virtual bool withdraw(double amount);
    
    // --- Static Utility Functions ---
    // 'static' means these belong to the class blueprint itself, not a specific account object
    static void printAccount(const BankAccount& account);
    static BankAccount* createAccountFromInput();
    

    

    

private:
    std::string accountNumber;
    std::string accountHolderName;
    double accountBalance;
};

#endif // BANKACCOUNT_H
