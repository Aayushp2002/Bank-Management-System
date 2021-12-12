#include "Client.h"
#include <iostream> 
using namespace std;

// method definitions
void Client::setID(int i) {
    id = i;
}

int Client::getID() {
    return id;
}

void Client::setName(string fn, string ln) {
    firstName = fn;
    lastName = ln;
}

string Client::getFirstName() {
    return firstName;
}

string Client::getLastName() {
    return lastName;
}

// constructor
Client::Client(string i, string fn, string ln) {
    id = stoi(i);
    firstName = fn;
    lastName = ln;
    checking = NULL;
    saving = NULL;
}