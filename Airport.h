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
public:
    Airport(string& code,string& name,string& city,string& country,double latitude,double longitude) : code(code), name(name), city(city), country(country), latitude(latitude), longitude(longitude) {}
    void printAirport();
    bool operator==(const Airport& other) const {
        return code == other.code &&
               name == other.name &&
               city == other.city &&
               country == other.country &&
               latitude == other.latitude &&
               longitude == other.longitude;
    }

    const string &getCode() const;

    const string &getName() const;

    const string &getCity() const;

    const string &getCountry() const;

    double getLatitude() const;

    double getLongitude() const;

};

#endif //FLIGHT_MANAGEMENT_SYSTEM_AIRPORT_H
