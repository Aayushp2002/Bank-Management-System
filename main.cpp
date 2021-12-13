#include <iostream>
#include "BankSystem.h"
using namespace std;



int main() {
    // app header
    cout << "Bank System App!" << endl << endl;

    // bank system object
    BankSystem bankAccount("7", "Kevin", "Durant");
    bankAccount.start();
}
