#include <iostream>
using namespace std;

class ATM {
private:
    int pin;
    double balance;

public:
    // Constructor to initialize ATM with PIN and balance
    ATM(int p, double b) {
        pin = p;
        balance = b;
    }

    // Method to handle user login
    bool login(int enteredPin) {
        return enteredPin == pin;
    }

    // Method to check balance
    void checkBalance() {
        cout << "Your current balance is: $" << balance << endl;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds or invalid withdrawal amount!" << endl;
        }
    }
};

int main() {
    ATM myATM(1234, 50000000000000); // PIN = 1234, Initial balance = $50000000000000
    int enteredPin, choice;
    double amount;

    cout << "Welcome to the ATM!" << endl;
    cout << "Please enter your PIN: ";
    cin >> enteredPin;

    if (!myATM.login(enteredPin)) {
        cout << "Incorrect PIN. Access denied!" << endl;
        return 0;
    }

    do {
        cout << "\nATM Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myATM.checkBalance();
                break;

            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                myATM.deposit(amount);
                break;

            case 3:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                myATM.withdraw(amount);
                break;

            case 4:
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again!" << endl;
        }
    } while (choice != 4);

    return 0;
}
