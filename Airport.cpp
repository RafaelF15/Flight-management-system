//
// Created by Rafael on 17/12/2023.
//

#include "Airport.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Airport::printAirport() {
    cout << "Code: " << this->code << "; Name: " << this->name << "; City: " << this->city << "; Country: " << this->country << "; Latitude: "<< fixed << setprecision(6) << this->latitude << "; Longitude: " << this->longitude << endl;
}

const string &Airport::getCode() const {
    return code;
}

const string &Airport::getName() const {
    return name;
}

const string &Airport::getCity() const {
    return city;
}

const string &Airport::getCountry() const {
    return country;
}

double Airport::getLatitude() const {
    return latitude;
}

double Airport::getLongitude() const {
    return longitude;
}

