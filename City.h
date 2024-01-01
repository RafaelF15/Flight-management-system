

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
    vector<Airport> getAirports();
    void addAirport(Airport a);

    const string &getName() const;
    const string &getCountry() const;

    void setName(string name);
    void setCountry(string country);

};


#endif //FLIGHT_MANAGEMENT_SYSTEM_CITY_H
