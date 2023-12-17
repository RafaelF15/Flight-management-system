//
// Created by Rafael on 17/12/2023.
//

#ifndef FLIGHT_MANAGEMENT_SYSTEM_AIRPORT_H
#define FLIGHT_MANAGEMENT_SYSTEM_AIRPORT_H

#include "string"
using namespace std;

class Airport {
    string code;
    string name;
    string city;
    string country;
    double latitude;
    double longitude;

    Airport(string code, string name, string city, string country, double latitude, double longitude) : code(code), name(name), city(city), country(country), latitude(latitude), longitude(longitude){}

};

#endif //FLIGHT_MANAGEMENT_SYSTEM_AIRPORT_H
