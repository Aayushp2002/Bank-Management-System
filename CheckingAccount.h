#include <iostream>
#include "Account.h"
using namespace std;

#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

class CheckingAccount : public Account {
    // public members
public:
    CheckingAccount(float amount);
    void withdraw(float amount);
};

#endif