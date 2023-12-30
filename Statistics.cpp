//
// Created by Rafael on 27/12/2023.
//

#include "Statistics.h"
#include <unordered_set>

int Statistics::getNumAirports(Graph<Airport> g) {
    // tirei linha com um cout que estava a mais
    return g.getNumVertex();
}

int Statistics::getNumFlights(Graph<Airport> g) {
    // tirei linha com um cout que estava a mais
    int edgeCount = 0;
    for(Vertex<Airport>* v: g.getVertexSet()){
        edgeCount += v->getAdj().size();
    }
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
int Statistics::getNumAirlinesFromAirport(Graph<Airport> g, unordered_map<string,Airport> airportMap ,string code) {
    try {
        set<string> aux = {};
        Airport a = airportMap.at(code);
        Vertex<Airport>* v = g.findVertex(a);
        for (auto e: v->getAdj()) {
            aux.insert(e.getFlight().getAirline().getCode());
        }
        cout << '\n' << "There are " << aux.size() << " different airlines available from airport: '" << a.getName() << "' of code: " << a.getCode() << "." << endl;
        return aux.size();
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
    cout << '\n' << "There are " << count << " reachable airports from: " << s->getInfo().getName() << "." << endl;
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


int Statistics::numReachableAirportsXFlights(Graph<Airport> g, unordered_map<string, Airport> airportMap, string code, int k) {
    vector<Airport> res;
    queue<pair<Vertex<Airport>*, int>> q;

    for(Vertex<Airport>* v : g.getVertexSet()) v->setVisited(false);

    Vertex<Airport>* s = g.findVertex(airportMap.at(code));

    q.push({s, 0});
    s->setVisited(true);

    while (!q.empty()){
        Vertex<Airport>* v = q.front().first;
        int currentDistance = q.front().second;
        q.pop();

        if(currentDistance <= k){
            res.push_back(v->getInfo());
        }

        for(Edge<Airport> e : v->getAdj()){
            Vertex<Airport>* v1 = e.getDest();
            if(!v1->isVisited()){
                q.push({v1, currentDistance+1});
                v1->setVisited(true);
            }
        }
    }
    cout << '\n' << "There are " << res.size() << " airports reachable from " << s->getInfo().getName() << " with " << k << " or less lay-overs." << endl;
    return res.size();
}

int Statistics::numReachableCitiesXFlights(Graph<Airport> g, unordered_map<string, Airport> airportMap, string code, int k) {
    vector<Airport> res;
    queue<pair<Vertex<Airport>*, int>> q;

    for(Vertex<Airport>* v : g.getVertexSet()) v->setVisited(false);

    Vertex<Airport>* s = g.findVertex(airportMap.at(code));

    q.push({s, 0});
    s->setVisited(true);

    while (!q.empty()){
        Vertex<Airport>* v = q.front().first;
        int currentDistance = q.front().second;
        q.pop();

        if(currentDistance <= k){
            res.push_back(v->getInfo());
        }

        for(Edge<Airport> e : v->getAdj()){
            Vertex<Airport>* v1 = e.getDest();
            if(!v1->isVisited()){
                q.push({v1, currentDistance+1});
                v1->setVisited(true);
            }
        }
    }

    int cityCount = 0;
    for (const Airport& airport : res) {
        if (airport.getCity() != "") {
            cityCount++;
        }
    }

    cout << '\n' << "There are " << cityCount << " cities reachable from " << s->getInfo().getName() << " with " << k << " or less lay-overs." << endl;
    return cityCount;
}

int Statistics::numReachableCountriesXFlights(Graph<Airport> g, unordered_map<string, Airport> airportMap, string code, int k) {
    unordered_set<string> uniqueCountries;
    queue<pair<Vertex<Airport>*, int>> q;

    for (Vertex<Airport>* v : g.getVertexSet()) {
        v->setVisited(false);
    }

    Vertex<Airport>* s = g.findVertex(airportMap.at(code));

    q.push({s, 0});
    s->setVisited(true);

    while (!q.empty()) {
        Vertex<Airport>* v = q.front().first;
        int currentDistance = q.front().second;
        q.pop();

        if (currentDistance <= k) {
            uniqueCountries.insert(v->getInfo().getCountry());
        }

        for (Edge<Airport> e : v->getAdj()) {
            Vertex<Airport>* v1 = e.getDest();
            if (!v1->isVisited()) {
                q.push({v1, currentDistance + 1});
                v1->setVisited(true);
            }
        }
    }

    int countryCount = static_cast<int>(uniqueCountries.size());
    cout << '\n' << "There are " << countryCount << " countries reachable from " << s->getInfo().getName() << " with " << k << " or less lay-overs." << endl;
    return countryCount;
}
