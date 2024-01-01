
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

void Airline::setCode(string code){this->code = code;}
void Airline::setName(string name){this->name = name;}
void Airline::setCallsign(string callsign){this->callsign = callsign;}
void Airline::setCountry(string country){this->country = country;}

void Airline::addFlight() {
    numFlights++;
}

int Airline::getNumFlights() const {
    return numFlights;
}

