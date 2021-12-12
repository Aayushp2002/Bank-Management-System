#include "Account.h"
#include <iostream>

// method definitions
float Account::getBalance() {
    return balance;
}

void Account::deposit(float amount) {
    balance += amount;
}