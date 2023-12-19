//
// Created by Rafael on 17/12/2023.
//

#include "Reading.h"
#include "Graph.h"
#include "Airline.h"
#include "Airport.h"
#include "City.h"
#include "Flight.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <unordered_map>

using namespace std;

/*
 * Ideas for the reading process:
 * Read the airports first -> They are the Vertexes of the graph;
 * Read the airlines saving them in a hash map, so we can find the airline when reading the flights;
 * Read the flights -> they are the Edges of the graph;
 */

void Reading::readAirports(Graph<Airport> &g) {
    string code, name, city, country, header;
    double latitude, longitude;
    ifstream file("../Data/airports.csv");
    if(file.is_open()){
        getline(file, header);
        for(string line; getline(file, line);){
            istringstream in(line);
            getline(in, code, ',');
            getline(in, name, ',');
            getline(in, city, ',');
            getline(in, country, ',');
            in >> fixed >> setprecision(6) >> latitude;
            in.ignore();
            in >> fixed >> setprecision(6) >> longitude;
            Airport a = Airport(code, name, city, country, latitude, longitude);
            g.addVertex(a);
        }
    }
}

void Reading::readAirlines(unordered_map<string, Airline>& m) {
    string code, name, callSign, country, header;
    ifstream file("../Data/airlines.csv");
    if(file.is_open()){
        getline(file, header);
        for(string line; getline(file, line);){
            istringstream in(line);
            getline(in, code, ',');
            getline(in, name, ',');
            getline(in, callSign, ',');
            getline(in, country, '\n');
            Airline a = Airline(code, name, callSign, country);
            m.emplace(code, a);
        }
    }
}