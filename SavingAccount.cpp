#include "SavingAccount.h"

// constructor
SavingAccount::SavingAccount(float amount, float rate) {
    savingRate = rate;
    balance = amount;
}

// method definitions
void SavingAccount::setSavingRate(float rate) {
    savingRate = rate;
}

float SavingAccount::getSavingRate() {
    return savingRate;
}

void SavingAccount::transfer(CheckingAccount& checkingAcc, float amount) {
    if (amount > balance) 
        cout << "It cannot withdraw an amount greater than the balance. No changes were done to the balance.";
    else {
        balance -= amount;
        checkingAcc.deposit(amount);
    }
}