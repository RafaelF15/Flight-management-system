//
// Created by Rafael on 17/12/2023.
//

#include "City.h"

const string &City::getName() const {return name;}
const string &City::getCountry() const {return country;}

void City::setName(string name){name= name;}
void City::setCountry(string country) {country = country;}


vector<Airport> City::getAirports() {
    return airports;
}

void City::addAirport(Airport a) {
    airports.push_back(a);
}

