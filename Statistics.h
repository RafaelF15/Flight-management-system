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
#include <stack>
#include <unordered_set>

class Statistics {
public:
    static int getNumAirports(Graph<Airport> g);
    static int getNumFlights(Graph<Airport> g);
    static int getNumFlightsFromAirport(Graph<Airport> g,unordered_map<string,Airport> airportMap, string code);
    static int getNumAirlinesFromAirport(Graph<Airport> g,unordered_map<string,Airport> airportMap, string code);
    static int getNumFlightsPerCity(Graph<Airport> g, unordered_map<string, City> citymap, string cityName, string country);
    static int getNumFlightsPerAirline(unordered_map<string, Airline> a, string code);
    static int getNumFlightsFromAirportToDifferentCountries(Graph<Airport> g, unordered_map<string,Airport> airportMap, string code);
    static int getNumFlightsFromCityToDifferentCountries(Graph<Airport> g, unordered_map<string, City> cityMap, string cityName, string country);
    static int getNumOfReachableAirportsFromAirport(Graph<Airport> g, unordered_map<string,Airport> airportMap, string code);
    static void dfsReachAirportFromAirport(Vertex<Airport>* v, vector<Airport>& airports);
    static int numReachableAirportsXFlights(Graph<Airport> g, unordered_map<string, Airport> airportMap, string code, int k);
    static pair<int, vector<Airport>> maximumTripbfs(Graph<Airport> g, Vertex<Airport>* v);
    static int findDiameter(Graph<Airport> g);
    static int articulationPoints(Graph<Airport>* g, unordered_map<string, Airport> airportMap);
    static void articulationPointsDfs(Graph<Airport>* g, Vertex<Airport> *v, unordered_set<string>& l, int& i);
    static int numReachableCitiesXFlights(Graph<Airport> g, unordered_map<string, Airport> airportMap, string code, int k);
    static int numReachableCountriesXFlights(Graph<Airport> g, unordered_map<string, Airport> airportMap, string code, int k);
    static void bestFlightAirportToAirportByCode(Graph<Airport> g, string source, string dest, unordered_map<string, Airport>& airportMap);
    static Flight findFlight(Graph<Airport> g, string source, string dest, unordered_map<string, Airport>& airportMap);
    static void bestFlightCityToCity(Graph<Airport> g, string sourceCity, string SourceCountry, string destCity, string destCountry);
    static vector<string> getTopAirportsByFlights(Graph<Airport> g, int k);
};
#endif //FLIGHT_MANAGEMENT_SYSTEM_STATISTICS_H
