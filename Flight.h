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
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_FLIGHT_H
