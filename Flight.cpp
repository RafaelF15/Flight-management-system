
#include <iostream>
#include "Flight.h"

void Flight::printFlight() {
    cout << "Source: " << this->source.getName() << "; Destination: " << this->target.getName()
    << "; Airline: " << this->airline.getCode() << endl;
}

Airline &Flight::getAirline() {
    return airline;
}