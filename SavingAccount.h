#include <iostream>
#include "Account.h"
#include "CheckingAccount.h"
using namespace std;


class SavingAccount : public Account {
    // private member
    float savingRate;

    // public members
public:
    SavingAccount(float amount, float rate);
    void setSavingRate(float rate);
    float getSavingRate();
    void transfer(CheckingAccount& checkingAcc, float amount);
};