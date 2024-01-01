

#ifndef FLIGHT_MANAGEMENT_SYSTEM_GRAPH_H
#define FLIGHT_MANAGEMENT_SYSTEM_GRAPH_H

#include <vector>
#include <string>
#include <queue>
#include "Flight.h"
using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

template <class T>
class Vertex {
    T info;
    vector<Edge<T>> adj;
    bool visited;
    bool processing;
    int num;
    int low;
    void addEdge(Vertex<T> *dest, Flight w);
    bool removeEdgeTo(Vertex<T> *d);

public:
    Vertex(T in);
    T getInfo() const;
    void setInfo(T in);
    bool isVisited() const;
    void setVisited(bool v);
    bool isProcessing() const;
    void setProcessing(bool p);
    const vector<Edge<T>> &getAdj() const;
    void setAdj(const vector<Edge<T>> &adj);

    int getNum() const;

    void setNum(int num);

    int getLow() const;

    void setLow(int low);

    friend class Graph<T>;
};

template <class T>
class Edge {
    Vertex<T> *dest;
    Flight flight;
public:
    Edge(Vertex<T> *d, Flight w);
    Vertex<T> *getDest() const;
    void setDest(Vertex<T> *dest);
    Flight getFlight() const;
    void setFlight(Flight flight);
    friend class Graph<T>;
    friend class Vertex<T>;
};

template <class T>
class Graph{
    vector<Vertex<T> *> vertexSet;
public:
    Vertex<T> *findVertex(const T &in) const;
    int getNumVertex() const;
    bool addVertex(const T &in);
    bool removeVertex(const T &in);
    bool addEdge(const T &sourc, const T &dest, Flight w);
    bool removeEdge(const T &sourc, const T &dest);
    vector<Vertex<T> * > getVertexSet() const;
};

template <class T>
Vertex<T>::Vertex(T in): info(in) {}

template <class T>
Edge<T>::Edge(Vertex<T> *d, Flight f): dest(d), flight(f) {}


template <class T>
int Graph<T>::getNumVertex() const {
    return vertexSet.size();
}

template <class T>
vector<Vertex<T> * > Graph<T>::getVertexSet() const {
    return vertexSet;
}

template<class T>
T Vertex<T>::getInfo() const {
    return info;
}

template<class T>
void Vertex<T>::setInfo(T in) {
    Vertex::info = in;
}

template<class T>
bool Vertex<T>::isProcessing() const {
    return processing;
}

template<class T>
void Vertex<T>::setProcessing(bool p) {
    Vertex::processing = p;
}

template<class T>
Vertex<T> *Edge<T>::getDest() const {
    return dest;
}

template<class T>
void Edge<T>::setDest(Vertex<T> *d) {
    Edge::dest = d;
}

template<class T>
Flight Edge<T>::getFlight() const {
    return flight;
}

template<class T>
void Edge<T>::setFlight(Flight flight) {
    Edge::flight = flight;
}

template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return NULL;
}

template <class T>
bool Vertex<T>::isVisited() const {
    return visited;
}

template <class T>
void Vertex<T>::setVisited(bool v) {
    Vertex::visited = v;
}

template<class T>
const vector<Edge<T>> &Vertex<T>::getAdj() const {
    return adj;
}

template <class T>
void Vertex<T>::setAdj(const vector<Edge<T>> &adj) {
    Vertex::adj = adj;
}

template <class T>
bool Graph<T>::addVertex(const T &in) {
    if ( findVertex(in) != NULL)
        return false;
    vertexSet.push_back(new Vertex<T>(in));
    return true;
}

template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, Flight w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    v1->addEdge(v2,w);
    return true;
}

template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, Flight w) {
    adj.push_back(Edge<T>(d, w));
}

template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    return v1->removeEdgeTo(v2);
}

template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
    for (auto it = adj.begin(); it != adj.end(); it++)
        if (it->dest  == d) {
            adj.erase(it);
            return true;
        }
    return false;
}

template <class T>
bool Graph<T>::removeVertex(const T &in) {
    for (auto it = vertexSet.begin(); it != vertexSet.end(); it++)
        if ((*it)->info  == in) {
            auto v = *it;
            vertexSet.erase(it);
            for (auto u : vertexSet)
                u->removeEdgeTo(v);
            delete v;
            return true;
        }
    return false;
}

template<class T>
int Vertex<T>::getNum() const {
    return num;
}

template<class T>
void Vertex<T>::setNum(int num) {
    Vertex::num = num;
}

template<class T>
int Vertex<T>::getLow() const {
    return low;
}

template<class T>
void Vertex<T>::setLow(int low) {
    Vertex::low = low;
}


#endif //FLIGHT_MANAGEMENT_SYSTEM_GRAPH_H
