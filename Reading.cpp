

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

//Time complexity O(n)
void Reading::readAirports(Graph<Airport> &g, unordered_map<string, Airport>& m, unordered_map<string,City>& cityMap) {
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
            m.emplace(code, a);
            g.addVertex(a);
            if(cityMap.find(city + country) != cityMap.end()){
                cityMap.at(city + country).addAirport(a);
            }
            else{
                vector<Airport> v;
                v.push_back(a);
                City c = City(city, country, v);
                cityMap.emplace(city + country, c);
            }
        }
    }
}
//Time complexity O(n)
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
//Time complexity O(n)
void Reading::readFlights(Graph<Airport> &g, unordered_map<string, Airport>& m, unordered_map<string, Airline>& a) {
    string source, target, airline, header;
    ifstream file("../Data/flights.csv");
    if(file.is_open()){
        getline(file, header);
        for(string line; getline(file, line);){
            istringstream in(line);
            getline(in, source, ',');
            getline(in, target, ',');
            getline(in, airline, '\r');
            Airport s = m.at(source);
            Airport t = m.at(target);
            Flight f = Flight(s, t, a.at(airline));
            a.at(airline).addFlight();
            g.addEdge(s, t, f);
        }
    }
}