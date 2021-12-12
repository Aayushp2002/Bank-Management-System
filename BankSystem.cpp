#include "BankSystem.h"
#include <vector>
#include <iostream>
using namespace std;

// displayMenu function
void displayMenu() {
    cout << "\n================== MENU ==================" << endl;
    cout << "1. Add a Checking account" << endl;
    cout << "2. Remove Checking account" << endl;
    cout << "3. Deposit into Checking Account" << endl;
    cout << "4. Withdraw from Checking Account" << endl;
    cout << "5. Add a Saving account" << endl;
    cout << "6. Remove Saving account" << endl;
    cout << "7. Deposit into Saving account" << endl;
    cout << "8. Transfer from Saving to Checking account" << endl;
    cout << "9. Exit" << endl;
}

// constructor
BankSystem::BankSystem(string i, string fn, string ln) {
    oneClient = new Client(i, fn, ln);
}

// AddCheckingDialog function
void BankSystem::AddCheckingDialog() {
    if (oneClient->checking != NULL) {
        cout << "The client already has a checking account\n";
        log.push_back("Invalid attempt to overwrite a checking account.");
    }
    else {
        float initialBalance;
        cout << "Enter the initial balance for checking account: ";
        cin >> initialBalance;
        CheckingAccount* check = new CheckingAccount(initialBalance);
        oneClient->checking = check;
        log.push_back("Checking account successfully created.");
    }
}

// RemoveCheckingDialog function
void BankSystem::RemoveCheckingDialog() {
    if (oneClient->checking != NULL) {
        CheckingAccount* check = oneClient->checking;
        oneClient->checking = NULL;
        delete check;
        log.push_back("Checking account successfully removed.");
    }
    else {
        cout << "The client does not have a checking account\n";
        log.push_back("Invalid attempt to remove a non-existing checking account.");
    }
}

// DepositCheckingDialog function
void BankSystem::DepositCheckingDialog() {
    if (oneClient->checking != NULL) {
        float amount;
        cout << "Enter the amount to deposit in checking account: ";
        cin >> amount;
        oneClient->checking->deposit(amount);
        log.push_back("$" + to_string(amount) + " successfully deposited in checking account.");
    }
    else {
        cout << "The client does not have a checking account\n";
        log.push_back("Invalid attempt to deposit in a non-existing checking account.");
    }
}

// WithdrawCheckingDialog function
void BankSystem::WithdrawCheckingDialog() {
    if (oneClient->checking != NULL) {
        float amount;
        cout << "Enter the amount to withdraw from checking account: ";
        cin >> amount;
        oneClient->checking->withdraw(amount);
        log.push_back("$" + to_string(amount) + " successfully withdrawn from checking account.");
    }
    else {
        cout << "The client does not have a checking account\n";
        log.push_back("Invalid attempt to withdraw from a non-existing checking account.");
    }
}

// AddSavingDialog function
void BankSystem::AddSavingDialog() {
    if (oneClient->saving != NULL) {
        cout << "The client already has a saving account\n";
        log.push_back("Invalid attempt to overwrite a saving account.");
    }
    else {
        float initialBalance, rate;
        cout << "Enter the initial balance for saving account: ";
        cin >> initialBalance;
        cout << "Enter the rate for saving account: ";
        cin >> rate;
        SavingAccount* sav = new SavingAccount(initialBalance, rate);
        oneClient->saving = sav;
        log.push_back("Saving account successfully created.");
    }
}

// RemoveSavingDialog function
void BankSystem::RemoveSavingDialog() {
    if (oneClient->saving != NULL)
    {
        SavingAccount* sav = oneClient->saving;
        oneClient->saving = NULL;
        delete sav;
        log.push_back("Saving account successfully removed.");
    }
    else {
        cout << "The client does not have a saving   account\n";
        log.push_back("Invalid attempt to remove a non-existing saving account.");
    }
}

// DepositSavingDialog function
void BankSystem::DepositSavingDialog() {
    if (oneClient->saving != NULL) {
        float amount;
        cout << "Enter the amount to deposit in saving account: ";
        cin >> amount;
        oneClient->saving->deposit(amount);
        log.push_back("$" + to_string(amount) + " successfully deposited in saving account.");
    }
    else {
        cout << "The client does not have a saving account\n";
        log.push_back("Invalid attempt to deposit in a non-existing saving account.");
    }
}

// TransferDialog function
void BankSystem::TransferDialog() {
    if (oneClient->saving == NULL) {
        cout << "The client does not have a saving account\n";
        log.push_back("Invalid attempt to use a non-existing saving account.");
    }

    else if (oneClient->checking == NULL) {
        cout << "The client does not have a checking account\n";
        log.push_back("Invalid attempt to use a non-existing checking account.");
    }

    else {
        float amt;
        cout << "Enter the amount to transfer: ";
        cin >> amt;
        oneClient->saving->transfer(*(oneClient->checking), amt);
        log.push_back("$" + to_string(amt) + " successfully transferred from saving to checking account.");
    }
}

// start function
void BankSystem::start() {
    int userInput;
    bool exit = false;
    displayMenu();

    while (exit == false) {
        cout << "Please pick an option [1-9]: ";
        cin >> userInput;

        if (userInput == 1) {
            AddCheckingDialog();
            displayMenu();
        }
        else if (userInput == 2) {
            RemoveCheckingDialog();
            displayMenu();
        }
        else if (userInput == 3) {
            DepositCheckingDialog();
            displayMenu();
        }
        else if (userInput == 4) {
            WithdrawCheckingDialog();
            displayMenu();
        }
        else if (userInput == 5) {
            AddSavingDialog();
            displayMenu();
        }
        else if (userInput == 6) {
            RemoveSavingDialog();
            displayMenu();
        }
        else if (userInput == 7) {
            DepositSavingDialog();
            displayMenu();
        }
        else if (userInput == 8) {
            TransferDialog();
            displayMenu();
        }
        else if (userInput == 9) {
            exit = true;
            // display logs
            cout << "================== LOGS ==================" << endl;
            for (int i = 0; i < log.size(); i++)
                cout << log[i] << endl;
        }
        else
            cout << "Invalid input!" << endl;
    }
}