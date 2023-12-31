#include <iostream>
#include "Graph.h"
#include "Airline.h"
#include "Airport.h"
#include "City.h"
#include "Flight.h"
#include "Reading.h"
#include "Statistics.h"
#include <unordered_map>
using namespace std;

int main() {
    Graph<Airport> g; // Main graph, has airports as vertexes and flights as edges, edge weight has been adapted to save the airline that is responsible for the flight;
    unordered_map<string, City> cityMap;
    //IMPORTANT : whenever using the citymap, the keys are of the following format: "ParisFrance"  There are multiple cities with the same name in different countries;
    //You can just use string concatenation: Key = city + country;
    unordered_map<string, Airline> airlineMap; // Find airline by code
    unordered_map<string, Airport> airportMap; // Find airport by code
    Reading::readAirports(g, airportMap, cityMap); // Reads airports from files and adds them to the graph as vertexes (also puts them in the airline map for fast searching if needed)
    Reading::readAirlines(airlineMap); // Reads airlines and puts them on the airline map for fast searching if needed
    Reading::readFlights(g, airportMap, airlineMap); // Reads flights from the file, adds them to the graph as vertexes, uses the two maps mentioned earlier to get airlines or airports from their code;
    // All read functions are now functional
    Statistics::getNumFlights(g);
    Statistics::getNumAirports(g);
    Statistics::getNumFlightsFromAirport(g, airportMap, "ORY");
    Statistics::getNumFlightsFromAirport(g, airportMap, "CDG");
    Statistics::getNumFlightsPerCity(g, cityMap, "Paris", "France");
    Statistics::getNumFlightsPerAirline(airlineMap, "IBE");
    Statistics::getNumFlightsFromAirportToDifferentCountries(g, airportMap, "JFK");
    Statistics::getNumFlightsFromCityToDifferentCountries(g, cityMap, "Paris", "France");
    Statistics::getNumOfReachableAirportsFromAirport(g, airportMap, "SSR");
    Statistics::numReachableAirportsXFlights(g, airportMap, "SSR", 2);
    //Statistics::findDiameter(g);
    Statistics::articulationPoints(&g);
}
