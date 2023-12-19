//
// Created by Rafael on 17/12/2023.
//

#include <iostream>
#include "Flight.h"

void Flight::printFlight() {
    cout << "Source: " << this->source.getName() << "; Destination: " << this->target.getName()
    << "; Airline: " << this->airline.getCode() << endl;
}