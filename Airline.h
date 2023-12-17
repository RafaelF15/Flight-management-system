//
// Created by Rafael on 17/12/2023.
//

#ifndef FLIGHT_MANAGEMENT_SYSTEM_AIRLINE_H
#define FLIGHT_MANAGEMENT_SYSTEM_AIRLINE_H

#include "string"
using namespace std;

class Airline {
    string code;
    string name;
    string callsign;
    string country;

    Airline(string code, string name, string callsign, string country) :code(code), name(name), callsign(callsign), country(country){}

};


#endif //FLIGHT_MANAGEMENT_SYSTEM_AIRLINE_H
