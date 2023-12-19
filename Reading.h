//
// Created by Rafael on 17/12/2023.
//

#ifndef FLIGHT_MANAGEMENT_SYSTEM_READING_H
#define FLIGHT_MANAGEMENT_SYSTEM_READING_H

#include <unordered_map>
#include "Graph.h"
#include "Airline.h"
#include "Airport.h"
#include "City.h"
#include "Flight.h"
#include "Reading.h"
using namespace std;

class Reading {
public:
    static void readAirports(Graph<Airport> &g, unordered_map<string, Airport>& m);
    static void readAirlines(unordered_map<string, Airline>& m) ;
    static void readFlights(Graph<Airport> &g, unordered_map<string,Airport>& m, unordered_map<string, Airline>& a);

};


#endif //FLIGHT_MANAGEMENT_SYSTEM_READING_H
