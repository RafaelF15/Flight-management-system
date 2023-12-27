//
// Created by Rafael on 27/12/2023.
//

#ifndef FLIGHT_MANAGEMENT_SYSTEM_STATISTICS_H
#define FLIGHT_MANAGEMENT_SYSTEM_STATISTICS_H

#include <iostream>
#include "Graph.h"
#include "Airline.h"
#include "Airport.h"
#include "City.h"
#include "Flight.h"
#include "Reading.h"
#include <unordered_map>

class Statistics {
public:
    static int getNumAirports(Graph<Airport> g);
    static int getNumFlights(Graph<Airport> g);

};


#endif //FLIGHT_MANAGEMENT_SYSTEM_STATISTICS_H
