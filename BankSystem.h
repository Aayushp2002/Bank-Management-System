#include <iostream>
#include <vector>
using namespace std;
#include "Client.h"

class BankSystem {
    // private members
private:
    vector<string> log;
    Client* oneClient;

    // public members
public:
    BankSystem(string i, string fn, string ln);
    void start();
    void AddCheckingDialog();
    void RemoveCheckingDialog();
    void DepositCheckingDialog();
    void WithdrawCheckingDialog();
    void AddSavingDialog();
    void RemoveSavingDialog();
    void DepositSavingDialog();
    void TransferDialog();
};