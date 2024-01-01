//
// Created by Rafael on 27/12/2023.
//

#include "Statistics.h"
#include <unordered_set>
#include <algorithm>

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
    Airport a = airportMap.at(code);
    Vertex<Airport>* v = g.findVertex(a);
    cout << '\n' << "There are " << v->getAdj().size() << " flights available from airport: '" << a.getName() << "' of code: " << a.getCode() << "." << endl;
    return v->getAdj().size();
}
int Statistics::getNumAirlinesFromAirport(Graph<Airport> g, unordered_map<string,Airport> airportMap ,string code) {
        set<string> aux = {};
        Airport a = airportMap.at(code);
        Vertex<Airport>* v = g.findVertex(a);
        for (auto e: v->getAdj()) {
            aux.insert(e.getFlight().getAirline().getCode());
        }
        cout << '\n' << "There are " << aux.size() << " different airlines available from airport: '" << a.getName() << "' of code: " << a.getCode() << "." << endl;
        return aux.size();
}

int Statistics::getNumFlightsPerCity(Graph<Airport> g, unordered_map<std::string, City> cityMap, string cityName, string country) {
    int numFlights = 0;
    string key = cityName + country;
    City c = cityMap.at(key);
    for(Airport a: c.getAirports()){
        Vertex<Airport>* v = g.findVertex(a);
        numFlights += v->getAdj().size();
    }
    cout << '\n' << "There are " << numFlights << " flights available from " << cityName << "," << country << "." << endl;
    return numFlights;

}

int Statistics::getNumFlightsPerAirline(unordered_map<std::string, Airline> a, string code) {
    int num = a.at(code).getNumFlights();
    cout << '\n' << "The airline " << a.at(code).getName() << " has " << num << " flights available.";
    return num;
}

int Statistics::getNumFlightsFromAirportToDifferentCountries(Graph<Airport> g, unordered_map<string, Airport> airportMap, string code) {
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
    return count;
}

int Statistics::getNumFlightsFromCityToDifferentCountries(Graph<Airport> g, unordered_map<string, City> cityMap, string cityName, string country) {
    int numFlights = 0;
    unordered_map<string,int> m;
    string key = cityName + country;
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
    return numFlights;
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
    cout << '\n' << "There are " << res.size()-1 << " airports reachable from " << s->getInfo().getName() << " with " << k << " or less lay-overs." << endl;
    return res.size()-1;
}


pair<int, vector<Airport>> Statistics::maximumTripbfs(Graph<Airport> g, Vertex<Airport>* v) {
    queue<pair<Vertex<Airport>*, int>> q;
    for(Vertex<Airport>* v : g.getVertexSet()) v->setVisited(false);
    Vertex<Airport>* s = g.findVertex(v->getInfo());
    q.push({s, 0});
    s->setVisited(true);
    int distance = 0;
    vector<Airport> airports;

    while(!q.empty()){
        Vertex<Airport>* v1 = q.front().first;
        int currentDistance = q.front().second;
        q.pop();
        if(currentDistance > distance) {
            distance = currentDistance;
            airports.clear();
            airports.push_back(v1->getInfo());
        }
        else if(currentDistance == distance){
            airports.push_back(v1->getInfo());
        }
        for(Edge<Airport> e : v1->getAdj()){
            Vertex<Airport>* v2 = e.getDest();
            if(!v2->isVisited()){
                q.push({v2, currentDistance+1});
                v2->setVisited(true);
            }
        }
    }
    return {distance, airports};
}

int Statistics::findDiameter(Graph<Airport> g) {
    int diameter = 0;
    vector<Airport> airports;
    Airport start = g.getVertexSet()[0]->getInfo();
    for(Vertex<Airport>* v : g.getVertexSet()){
        pair<int, vector<Airport>> p = maximumTripbfs(g, v);
        if (diameter != max(diameter, p.first)){
            diameter = max(diameter, p.first);
            airports = p.second;
            start = v->getInfo();
        }
    }
    cout << '\n' <<"The maximum trip passes trough " << diameter << " airports starting at " << start.getName() << " and ending at one of the following: " << endl;
    for(Airport a: airports){
        cout << '\n' << a.getName() << endl;
    }
    return diameter;
}

int Statistics::articulationPoints(Graph<Airport> *g, unordered_map<string, Airport> airportMap) {
    unordered_set<string> res;
    int index = 1;
    for(Vertex<Airport>* v : g->getVertexSet()){
        v->setVisited(false);
        v->setProcessing(false);
    }

    for(Vertex<Airport>* v : g->getVertexSet()){
        if(!v->isVisited())
            articulationPointsDfs(g,v,res,index);
    }
    cout<< '\n' << "There are " << res.size() << " airports essential to the network's circulation capability" << endl;
    cout << '\n' << "The airports are: " << endl;
    for(string s : res){
        cout << '\n' << airportMap.at(s).getName() << endl;
    }
    return res.size();
}

void Statistics::articulationPointsDfs(Graph<Airport> *g, Vertex<Airport> *v, unordered_set<string> &l, int &i) {
    v->setNum(i);
    v->setLow(i);
    i++;
    v->setVisited(true);
    v->setProcessing(true);
    int count = 0;

    for(Edge<Airport> e : v->getAdj()){
        Vertex<Airport>* w = e.getDest();
        if(!w->isVisited()){
            count++;
            articulationPointsDfs(g,w,l,i);
            v->setLow(min(v->getLow(), w->getLow()));
            if(w->getLow() >= v->getNum() && v != g->getVertexSet()[0]){
                l.insert(v->getInfo().getCode());
            }
            if(w->getLow() >= v->getNum() && v == g->getVertexSet()[0]){
                if(count > 1)
                    l.insert(v->getInfo().getCode());
            }
        }
        else {
            v->setLow(min(v->getLow(), w->getNum()));
        }
    }
    v->setProcessing(false);
}

int Statistics::numReachableCitiesXFlights(Graph<Airport> g, unordered_map<string, Airport> airportMap, string code, int k) {
    vector<Airport> res;
    queue<pair<Vertex<Airport> *, int>> q;

    for (Vertex<Airport> *v: g.getVertexSet()) v->setVisited(false);

    Vertex<Airport> *s = g.findVertex(airportMap.at(code));

    q.push({s, 0});
    s->setVisited(true);

    while (!q.empty()) {
        Vertex<Airport> *v = q.front().first;
        int currentDistance = q.front().second;
        q.pop();

        if (currentDistance <= k) {
            res.push_back(v->getInfo());
        }

        for (Edge<Airport> e: v->getAdj()) {
            Vertex<Airport> *v1 = e.getDest();
            if (!v1->isVisited()) {
                q.push({v1, currentDistance + 1});
                v1->setVisited(true);
            }
        }
    }
        set<string> auxCity = {};
        for (auto ap: res) {
            auxCity.insert(ap.getCity());
        }
        int cityCount = auxCity.size();
        cout << '\n' << "There are " << cityCount-1 << " cities reachable from " << s->getInfo().getName() << " with "
             << k << " or less lay-overs." << endl;
        return cityCount-1;
    }
    int Statistics::numReachableCountriesXFlights(Graph<Airport> g, unordered_map<string, Airport> airportMap, string code,
                                              int k) {
        unordered_set<string> uniqueCountries;
        queue<pair<Vertex<Airport> *, int>> q;

        for (Vertex<Airport> *v: g.getVertexSet()) {
            v->setVisited(false);
        }

        Vertex<Airport> *s = g.findVertex(airportMap.at(code));

        q.push({s, 0});
        s->setVisited(true);

        while (!q.empty()) {
            Vertex<Airport> *v = q.front().first;
            int currentDistance = q.front().second;
            q.pop();

            if (currentDistance <= k) {
                uniqueCountries.insert(v->getInfo().getCountry());
            }

            for (Edge<Airport> e: v->getAdj()) {
                Vertex<Airport> *v1 = e.getDest();
                if (!v1->isVisited()) {
                    q.push({v1, currentDistance + 1});
                    v1->setVisited(true);
                }
            }
        }

        int countryCount = static_cast<int>(uniqueCountries.size());
        cout << '\n' << "There are " << countryCount-1 << " countries reachable from " << s->getInfo().getName()
             << " with " << k << " or less lay-overs." << endl;
        return countryCount -1;
    }

    vector<string> Statistics::getTopAirportsByFlights(Graph<Airport> g, int k) {
        vector<string> topAirports;

        priority_queue<pair<int, Vertex<Airport> *>> pq;

        for (Vertex<Airport> *v: g.getVertexSet()) {
            int numFlights = static_cast<int>(v->getAdj().size());
            pq.push({numFlights, v});
        }

        for (int i = 0; i < k && !pq.empty(); ++i) {
            pair<int, Vertex<Airport> *> topAirport = pq.top();
            pq.pop();

            string airportInfo = to_string(i + 1) + ") " + topAirport.second->getInfo().getCode() + " - " +
                                 topAirport.second->getInfo().getName();

            topAirports.push_back(airportInfo);
        }
        for (const string &airportInfo: topAirports) {
            cout << airportInfo << endl;
        }
        return topAirports;
    }



void Statistics::bestFlightAirportToAirportByCode(Graph<Airport> g, std::string source, std::string dest, unordered_map<string, Airport>& airportMap) {
    unordered_map<Vertex<Airport>*, int> distance;
    unordered_map<Vertex<Airport>*, Vertex<Airport>*> parent;
    queue<Vertex<Airport>*> q;
    for(Vertex<Airport>* b : g.getVertexSet()) {
        b->setVisited(false);
        distance[b] = INT16_MAX;
    }

    Vertex<Airport>* s = g.findVertex(airportMap.at(source));
    Vertex<Airport>* d = g.findVertex(airportMap.at(dest));

    distance[s] = 0;

    q.push(s);
    s->setVisited(true);
    parent[s] = nullptr;


    while (!q.empty()){

        Vertex<Airport>* v = q.front();
        v->setVisited(true);
        q.pop();


        for(Edge<Airport> e : v->getAdj()){
            Vertex<Airport>* v1 = e.getDest();
            if(!v1->isVisited()){
                cout << '\n' <<"Visiting " << v1->getInfo().getCode() << endl;
                if(distance[v] + 1 < distance[v1]){
                    parent[v1] = v;
                    cout << v1->getInfo().getCode() << " new parent is: " << v->getInfo().getCode() << endl;
                    distance[v1] = distance[v] + 1;
                    cout<< '\n' << v1->getInfo().getCode() << " :: " << distance[v1];
                }
                q.push(v1);
                v1->setVisited(true);
            }
        }
    }
    cout << '\n' << d->getInfo().getCode() << " has parent: " << parent[d]->getInfo().getCode() << endl;
    if (parent[d]) {
        stack<Vertex<Airport>*> path;
        Vertex<Airport>* current = d;
        while (current != nullptr) {
            path.push(current);
            current = parent[current];
        }

        while (!path.empty()) {
            cout << path.top()->getInfo().getCode() << " ";
            path.pop();
        }
        cout << endl;
    }
}

Flight Statistics::findFlight(Graph<Airport> g, std::string source, std::string dest, unordered_map<std::string, Airport> &airportMap) {

    Vertex<Airport>* s = g.findVertex(airportMap.at(source));
    Vertex<Airport>* d = g.findVertex(airportMap.at(dest));

    for(Edge<Airport> e : s->getAdj()){
        if(e.getDest() == d){
            return e.getFlight();
        }
    }
}