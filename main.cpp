#include <iostream>
#include "BankSystem.h"
using namespace std;

/*Group 2 Members

Hamzah Shakeel
Dan Pop
Aayush Patel
Faizan Bhatti
Ashraf Ahmed
*/ 

int main() {
    // app header
    cout << "Bank System App!" << endl << endl;

    // bank system object
    BankSystem bankAccount("7", "Kevin", "Durant");
    bankAccount.start();
}