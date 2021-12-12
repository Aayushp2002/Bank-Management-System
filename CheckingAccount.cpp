#include "CheckingAccount.h"


// method definitions
CheckingAccount::CheckingAccount(float amount) {
    balance = amount;
}

void CheckingAccount::withdraw(float amount) {
    if (amount > balance) 
        cout << "It cannot withdraw an amount greater than the balance. No changes were done to the balance.";
    else 
        balance -= amount;
}