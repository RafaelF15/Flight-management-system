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
