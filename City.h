//
// Created by Rafael on 17/12/2023.
//

#ifndef FLIGHT_MANAGEMENT_SYSTEM_CITY_H
#define FLIGHT_MANAGEMENT_SYSTEM_CITY_H

#include "Airport.h"
#include "vector"
#include "string"
using namespace std;

class City {
    string name;
    string country;
    vector<Airport> airports;

    City(string name, string country, vector<Airport> airports) : name(name), country(country), airports(airports) {}

};


#endif //FLIGHT_MANAGEMENT_SYSTEM_CITY_H
