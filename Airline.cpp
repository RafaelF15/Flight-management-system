//
// Created by Rafael on 17/12/2023.
//

#include "Airline.h"
#include <iostream>
using namespace std;

void Airline::printAirline() {
    cout << "Code: " << this->code << "; Name: " << this->name << "; Callsign: " << this->callsign << "; Country: " << this->country << endl;
}

const string &Airline::getCode() const {
    return code;
}

const string &Airline::getName() const {
    return name;
}

const string &Airline::getCallsign() const {
    return callsign;
}

const string &Airline::getCountry() const {
    return country;
}
