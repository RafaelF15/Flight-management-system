//
// Created by Rafael on 27/12/2023.
//

#include "Statistics.h"
#include <unordered_set>

int Statistics::getNumAirports(Graph<Airport> g) {
    cout << '\n' << "There are " << g.getNumVertex() << " airports available." << endl;
    return g.getNumVertex();
}

int Statistics::getNumFlights(Graph<Airport> g) {
    int edgeCount = 0;
    for(Vertex<Airport>* v: g.getVertexSet()){
        edgeCount += v->getAdj().size();
    }
    cout << '\n' << "There are " << edgeCount << " flights available." << endl;
    return edgeCount;
}

int Statistics::getNumFlightsFromAirport(Graph<Airport> g, unordered_map<string,Airport> airportMap ,string code) {
    try {
        Airport a = airportMap.at(code);
        Vertex<Airport>* v = g.findVertex(a);
        cout << '\n' << "There are " << v->getAdj().size() << " flights available from airport: '" << a.getName() << "' of code: " << a.getCode() << "." << endl;
        return v->getAdj().size();
    } catch (const out_of_range &e)
    {
        cerr << "There is no Airport with that code.";
    }
}

int Statistics::getNumFlightsPerCity(Graph<Airport> g, unordered_map<std::string, City> cityMap, string cityName, string country) {
    int numFlights = 0;
    string key = cityName + country;
    try {
        City c = cityMap.at(key);
        for(Airport a: c.getAirports()){
            Vertex<Airport>* v = g.findVertex(a);
            numFlights += v->getAdj().size();
        }
        cout << '\n' << "There are " << numFlights << " flights available from " << cityName << "," << country << "." << endl;

    } catch (const out_of_range &e)
    {
        cerr << "The city does not exist.";
    }
}

int Statistics::getNumFlightsPerAirline(unordered_map<std::string, Airline> a, string code) {
    try {
        int num = a.at(code).getNumFlights();
        cout << '\n' << "The airline " << a.at(code).getName() << " has " << num << " flights available.";
    } catch (const out_of_range &e)
    {
        cerr << "The airline does not exist.";
    }
}

int
Statistics::getNumFlightsFromAirportToDifferentCountries(Graph<Airport> g, unordered_map<string, Airport> airportMap, string code) {
    try {
        int count = 0;
        unordered_map<string,int> m;
        Airport a = airportMap.at(code);
        Vertex<Airport>* v = g.findVertex(a);
        for(Edge<Airport> e : v->getAdj()){
            if(m.find(e.getDest()->getInfo().getCountry()) == m.end()){
                count++;
                m.emplace(e.getDest()->getInfo().getCountry(), 0);
            }
        }
        cout << '\n' << "There are " << count << " possible countries reachable from " << a.getName() << " with only one flight.";

    } catch (const out_of_range &e)
    {
        cerr << "There is no Airport with that code.";
    }
}

int Statistics::getNumFlightsFromCityToDifferentCountries(Graph<Airport> g, unordered_map<string, City> cityMap, string cityName, string country) {
    int numFlights = 0;
    unordered_map<string,int> m;
    string key = cityName + country;
    try {
        City c = cityMap.at(key);
        for(Airport a: c.getAirports()){
            Vertex<Airport>* v = g.findVertex(a);
            for(Edge<Airport> e : v->getAdj()){
                if(m.find(e.getDest()->getInfo().getCountry()) == m.end()){
                    numFlights++;
                    m.emplace(e.getDest()->getInfo().getCountry(), 0);
                }
            }
        }
        cout << '\n' << "There are " << numFlights << " reachable countries from " << cityName << "," << country << " with only one flight." << endl;

    } catch (const out_of_range &e)
    {
        cerr << "The city does not exist.";
    }
}

int Statistics::getNumOfReachableAirportsFromAirport(Graph<Airport> g, unordered_map<string, Airport> airportMap, string code) {
    for(Vertex<Airport>* v1 : g.getVertexSet()){
        v1->setVisited(false);
    }
    int count = 0;
    vector<Airport> airports;
    Vertex<Airport>* s = g.findVertex(airportMap.at(code));

    dfsReachAirportFromAirport(s, airports);
    count = airports.size();
    cout << '\n' << "There are " << count << " reachable airports from: " << s->getInfo().getName() << endl;
    for(Airport a : airports){
        cout << '\n' << a.getName() << endl;
    }
    return count;
}

void Statistics::dfsReachAirportFromAirport(Vertex<Airport> *v, vector<Airport> &airports) {
    v->setVisited(true);
    airports.push_back(v->getInfo());
    for(Edge<Airport> e : v->getAdj()){
        if(!e.getDest()->isVisited()){
            dfsReachAirportFromAirport(e.getDest(), airports);
        }
    }
}
