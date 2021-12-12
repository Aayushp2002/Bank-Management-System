#include <string>
#include "CheckingAccount.h"
#include "SavingAccount.h"
using namespace std;


class Client {
    // private members
    int id;
    string firstName;
    string lastName;

    // public members
public:
    CheckingAccount* checking;
    SavingAccount* saving;

    Client(string i, string fn, string ln);
    void setName(string fn, string ln);
    string getFirstName();
    string getLastName();
    void setID(int);
    int getID();
};