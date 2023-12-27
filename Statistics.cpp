//
// Created by Rafael on 27/12/2023.
//

#include "Statistics.h"

int Statistics::getNumAirports(Graph<Airport> g) {
    cout << '\n' << "There are " << g.getNumVertex() << " airports available." << endl;
}

int Statistics::getNumFlights(Graph<Airport> g) {
    int edgeCount = 0;
    for(Vertex<Airport>* v: g.getVertexSet()){
        edgeCount += v->getAdj().size();
    }
    cout << '\n' << "There are " << edgeCount << " flights available." << endl;
}