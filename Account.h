#pragma once

class Account {
    // protected member
protected:
    float balance;

    // public members
public:
    virtual float getBalance();
    virtual void deposit(float amount);
};