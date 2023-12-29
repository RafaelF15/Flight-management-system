//
// Created by Rafael on 17/12/2023.
//

#include "City.h"
const string &City::getName() const {return name;}
const string &City::getCountry() const {return country;}
vector<Airport> City::getAirports() {return airports;}

void City::setName(string name){name= name;}
void City::setCountry(string country) {country = country;}


void City::addAirport(Airport ap) {airports.push_back(ap);} //adicionar aeroporto ao vetor de aeroportos da cidade