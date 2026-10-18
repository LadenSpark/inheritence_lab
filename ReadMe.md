# Bank Account Management System (Inheritance Lab)

A C++ banking management system demonstrating public inheritance, polymorphism, dynamic method dispatch, and proper memory management using virtual destructors. The application manages a polymorphic collection of account pointers (`std::vector<BankAccount*>`) supporting base accounts, fee-based checking accounts, and interest-bearing savings accounts.

---

## 1. BankAccount Class (Base Class)

The base class providing core account data attributes, overloaded operators, and virtual method interfaces for derived account types.

### Data Dictionary

| Attribute | Data Type | Description |
| :--- | :--- | :--- |
| `accountNumber` | `std::string` | Unique identifier string for the bank account. |
| `accountHolderName` | `std::string` | Full name of the person or entity holding the account. |
| `accountBalance` | `double` | Current liquid monetary funds stored in the account. |

### Methods List

| Method Signature | Return Type | Description |
| :--- | :--- | :--- |
| `BankAccount()` | (Constructor) | Default constructor initializing strings to empty and balance to `0.0`. |
| `BankAccount(const std::string& _accountNumber, const std::string& _accountHolderName, double _startingBalance)` | (Constructor) | Parameterized constructor setting account number, name, and non-negative initial balance. |
| `BankAccount(const BankAccount& other)` | (Constructor) | Copy constructor performing a deep copy of an existing account object. |
| `virtual ~BankAccount()` | (Destructor) | Virtual destructor ensuring proper resource cleanup through base class pointers. |
| `operator=(const BankAccount& other)` | `BankAccount&` | Copy assignment operator guarded against self-assignment. |
| `getAccountNumber() const` | `std::string` | Accessor method returning the unique account number. |
| `getAccountHolderName() const` | `std::string` | Accessor method returning the account holder name. |
| `getAccountBalance() const` | `double` | Accessor method returning the current account balance. |
| `setAccountHolderName(const std::string& name)` | `void` | Mutator method updating the account holder name. |
| `operator==(const BankAccount& other) const` | `bool` | Returns `true` if two accounts share the same account number. |
| `operator<(const BankAccount& other) const` | `bool` | Returns `true` if this account balance is less than the other account balance. |
| `operator>(const BankAccount& other) const` | `bool` | Returns `true` if this account balance is greater than the other account balance. |
| `operator+=(double amount)` | `BankAccount&` | Directly adds positive funds to balance in-place and returns `*this`. |
| `operator-=(double amount)` | `BankAccount&` | Directly subtracts positive funds if balance is sufficient and returns `*this`. |
| `deposit(double amount)` | `bool` | Adds funds if amount is positive; returns `true` on success, `false` otherwise. |
| `virtual bool withdraw(double amount)` | `bool` | Virtual method deducting funds if sufficient; overridden by derived classes. |
| `printAccount(const BankAccount& account)` | `void` (static) | Formats and prints account number, holder name, and balance to standard output. |
| `createAccountFromInput()` | `BankAccount` (static) | Prompts standard input and returns a newly constructed `BankAccount` object. |

---

## 2. CheckingAccount Class (Derived Class)

Specialized account class inheriting publicly from `BankAccount` that enforces a per-transaction service fee on withdrawals.

### Data Dictionary

| Attribute | Data Type | Description |
| :--- | :--- | :--- |
| `transactionFee` | `double` | Flat monetary fee charged in addition to the withdrawal amount. |

### Methods List

| Method Signature | Return Type | Description |
| :--- | :--- | :--- |
| `CheckingAccount()` | (Constructor) | Default constructor initializing base members and setting `transactionFee` to `0.0`. |
| `CheckingAccount(const std::string& _accountNumber, const std::string& _accountHolderName, double _startingBalance, double _transactionFee)` | (Constructor) | Parameterized constructor calling the base constructor and initializing `transactionFee`. |
| `virtual ~CheckingAccount()` | (Destructor) | Virtual destructor handling derived checking account cleanup. |
| `withdraw(double amount) override` | `bool` | Polymorphic override verifying funds cover `amount + transactionFee` before deducting both. |
| `getTransactionFee() const` | `double` | Accessor returning the current per-transaction fee. |
| `createCheckingAccountFromInput()` | `CheckingAccount*` (static) | Prompts console input for account data and fee, returning a heap-allocated pointer. |

---

## 3. SavingsAccount Class (Derived Class)

Specialized account class inheriting publicly from `BankAccount` that tracks an annual interest rate and calculates compounded yield.

### Data Dictionary

| Attribute | Data Type | Description |
| :--- | :--- | :--- |
| `interestRate` | `double` | Decimal interest rate applied to compute account earnings (e.g., `0.03` for 3%). |

### Methods List

| Method Signature | Return Type | Description |
| :--- | :--- | :--- |
| `SavingsAccount()` | (Constructor) | Default constructor initializing base members and setting `interestRate` to `0.0`. |
| `SavingsAccount(const std::string& _accountNumber, const std::string& _accountHolderName, double _startingBalance, double _interestRate)` | (Constructor) | Parameterized constructor calling the base constructor and initializing `interestRate`. |
| `virtual ~SavingsAccount()` | (Destructor) | Virtual destructor handling derived savings account cleanup. |
| `withdraw(double amount) override` | `bool` | Polymorphic override executing standard base account withdrawal rules. |
| `calculateInterest()` | `void` | Computes interest (`accountBalance * interestRate`) and deposits the earned yield into balance. |
| `getInterestRate() const` | `double` | Accessor returning the current interest rate decimal value. |
| `createSavingsAccountFromInput()` | `SavingsAccount*` (static) | Prompts console input for account data and interest rate, returning a heap-allocated pointer. |