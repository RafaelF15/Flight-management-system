//
// Created by Rafael on 17/12/2023.
//

#include "City.h"

vector<Airport> City::getAirports() {
    return airports;
}

void City::addAirport(Airport a) {
    airports.push_back(a);
}

const string &City::getName() const {
    return name;
}

const string &City::getCountry() const {
    return country;
}
