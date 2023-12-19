//
// Created by Rafael on 17/12/2023.
//

#include "Airline.h"
#include <iostream>
using namespace std;

void Airline::printAirline() {
    cout << "Code: " << this->code << "; Name: " << this->name << "; Callsign: " << this->callsign << "; Country: " << this->country << endl;
}
