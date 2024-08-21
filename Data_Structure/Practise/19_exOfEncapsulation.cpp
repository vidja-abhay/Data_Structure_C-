#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    double balance;
    int accountNumber;

public:
    BankAccount(string name, int accNum, double initialBalance) : 
        accountHolderName(name), accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    void displayInfo() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account("John Doe", 12345, 1000.0);

    account.displayInfo();
    account.deposit(500);
    account.withdraw(200);
    cout << "Current balance: " << account.getBalance() << endl;

    // This would cause a compilation error:
    // cout << account.balance;

    return 0;
}