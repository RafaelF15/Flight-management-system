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
public:
    Airline(string code, string name, string callsign, string country) :code(code), name(name), callsign(callsign), country(country){}
    void printAirline();

    const string &getCode() const;

    const string &getName() const;

    const string &getCallsign() const;

    const string &getCountry() const;

    void setCode(string code);
    void setName(string name);
    void setCallsign(string callsign);
    void setCountry(string country);

};


#endif //FLIGHT_MANAGEMENT_SYSTEM_AIRLINE_H
