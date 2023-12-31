//
// Created by Rafael on 17/12/2023.
//

#ifndef FLIGHT_MANAGEMENT_SYSTEM_FLIGHT_H
#define FLIGHT_MANAGEMENT_SYSTEM_FLIGHT_H

#include "Airport.h"
#include "Airline.h"


class Flight {
    Airport source, target;
    Airline airline;
public:
    Flight(Airport source, Airport target, Airline airline) : source(source), target(target), airline(airline) {}
    void printFlight();
    Airline &getAirline();
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_FLIGHT_H
