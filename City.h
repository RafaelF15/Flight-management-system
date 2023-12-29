//
// Created by Rafael on 17/12/2023.
//

#ifndef FLIGHT_MANAGEMENT_SYSTEM_CITY_H
#define FLIGHT_MANAGEMENT_SYSTEM_CITY_H

#include "Airport.h"
#include <vector>
#include <set>
using namespace std;
struct Country {
    string name;
    set<string> cities;
}; // conjunto de cidades de um país
class City {
    string name;
    string country;
    vector<Airport> airports;
public:

    City(string name, string country, vector<Airport> airports) : name(name), country(country), airports(airports) {}

    const string &getName() const;
    const string &getCountry() const;
    vector<Airport> getAirports();

    void setName(string name);
    void setCountry(string country);

    void addAirport(Airport ap);
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_CITY_H
