


/*
    Create a class representing a bank account with private member variables for
    account number, balance, and owner&#39;s name. Implement encapsulation by providing
    public methods to deposit, withdraw, and check balance.
*/

#include <bits/stdc++.h>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
    string ownerName;

public:
    BankAccount(string accNumber, double initialBalance, string owner) 
        : accountNumber(accNumber), balance(initialBalance), ownerName(owner) {
        cout << "Bank account created for " << ownerName << " with account number: " << accountNumber << endl;
        cout << "Initial balance: " << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit of $" << amount << " successful. New balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal of $" << amount << " successful. New balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        }
    }

    double checkBalance() {
        return balance;
    }

    ~BankAccount() {
        cout << "Bank account for " << ownerName << " with account number " << accountNumber << " is closed. Goodbye!" << endl;
    }
};

int main() {
    BankAccount myAccount("123456789", 1000.0, "John Doe");

    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);

    cout << "Current balance: $" << myAccount.checkBalance() << endl;

    return 0;
}
