#include <iostream>
#include "Graph.h"
#include "Airline.h"
#include "Airport.h"
#include "City.h"
#include "Flight.h"
#include "Reading.h"
#include <unordered_map>
using namespace std;

int main() {
    Graph<Airport> g;
    unordered_map<string, Airline> airlineMap;

    Reading::readAirports(g);
    Reading::readAirlines(airlineMap);
    
}
