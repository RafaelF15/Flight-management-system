#include <iostream>
#include "Graph.h"
#include "Airline.h"
#include "Airport.h"
#include "City.h"
#include "Flight.h"
#include "Reading.h"
#include "Statistics.h"
#include "Interface.h"
#include <unordered_map>
using namespace std;

void welcomePage();

void getStatistics();

void globalStatistic();

void exitProgram();
void lastPage();
void credits();
Graph<Airport> g; //inicializei aqui porque não estava a reconhecer se fosse dentro do main

void welcomePage() {
    cout << endl << "=========WELCOME PAGE=========" << endl;
    cout << endl << "Options:\n\t1-Get statistics\n\t5-Credits\n\te-Exit" <<endl;
    char input;
    while (true){
        cout << "Choose option:";
        cin >> input;

        switch (input) {
            case ('1'):
                getStatistics();
                return welcomePage();
                /*
            case ('2'):
                getFlights();
                return welcomePage();
            case ('3'):
                getApMethods();
                return welcomePage();
            case ('4'):
                otherInfo();
                return welcomePage();
                 */
            case ('5'):
                credits();
                return welcomePage();

            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;

        }
    }
}

void getStatistics(){
    cout << endl << "=========GET STATISTICS=========" << endl;
    cout << endl;
    cout << "Choose the type of statistics:" << endl;
    cout << endl << "Options:\n\t1-Global\n\t2-Airport\n\tb-Back\n\te-Exit"<<endl;
    char inputType;
    string inputDestination;
    while (true){
        cout << "Choose option:";
        cin >> inputType;
        switch (inputType) {
            case ('1'):
                globalStatistic();
                return getStatistics();
                /*
            case ('2'):
                Statistics::getNumFlightsFromAirport(g,)
                return getStatistics();

            case ('3'):
                cityStatistic();
                return getStatistics();
            case ('4'):
                airlineStatistic();
                return getStatistics();
            case ('5'):
                airportStatistic();
                return getStatistics();
                */
            case ('b'):
                return welcomePage();
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
void globalStatistic(){
    cout << endl << "=========GLOBAL STATISTICS=========" << endl;
    cout << endl;
    cout << "Choose the statistic:" << endl;
    cout << endl << "Options:\n\t1-Total airports\n\t2-Total flights\n\tb-Back\n\te-Exit"<<endl;

    char option;
    while (true){
        cout << "Choose option:";
        cin >> option;
        switch (option) {
            case ('1'):
                cout << '\n' << "There are " << Statistics::getNumAirports(g) << " airports available." << endl;
                lastPage();
                return getStatistics();
            case ('2'):
                cout << '\n' << "There are " << Statistics::getNumFlights(g) << " flights available." << endl;
                lastPage();
                return getStatistics();
                /*
            case ('3'):
                cout << "Number of countries: " << d_.totalCountries() << endl;
                lastPage();
                return getStatistics();
            case ('4'):
                cout << "Number of airlines: " << d_.totalAirlines() << endl;
                lastPage();
                return getStatistics();
            case ('5'):
                cout << "Number of cities: " << d_.totalCities() << endl;
                lastPage();
                return getStatistics();

                 */
            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}

void lastPage() {
    cout << endl << endl;
    cout << endl << "Options:\n\tb-Back\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option:";
        cin >> input;
        switch (input) {
            case ('b'):
                return;
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
void credits() {
    cout << endl << "=========CREDITS=========" << endl;
    cout << endl;
    cout << "Made by:" << endl;
    cout << "André Santos, up202207724" << endl; //ver problema dos acentos com outros pcs
    cout << "Iara Brás, up202208825" << endl; //mesmo que em cima
    cout << "Rafael Costa, up202205013" << endl;
    cout << endl << endl << "Options:\n\tb-Back\n\te-Exit"<< endl;
    char input;
    while (true) {
        cout << "Choose option:";
        cin >> input;

        switch (input) {
            case ('b'):
                return;
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}

void exitProgram() {
    cout << endl << "Exiting program..." << endl;
    throw 200;
}




int main() {
     // Graph<Airport> g;  Main graph, has airports as vertexes and flights as edges, edge weight has been adapted to save the airline that is responsible for the flight;
     // inicializado em cima do ficheiro, ver
    unordered_map<string, City> cityMap;
    //IMPORTANT : whenever using the citymap, the keys are of the following format: "ParisFrance"  There are multiple cities with the same name in different countries;
    //You can just use string concatenation: Key = city + country;
    unordered_map<string, Airline> airlineMap; // Find airline by code
    unordered_map<string, Airport> airportMap; // Find airport by code
    Reading::readAirports(g, airportMap,
                          cityMap); // Reads airports from files and adds them to the graph as vertexes (also puts them in the airline map for fast searching if needed)
    Reading::readAirlines(airlineMap); // Reads airlines and puts them on the airline map for fast searching if needed
    Reading::readFlights(g, airportMap,
                         airlineMap); // Reads flights from the file, adds them to the graph as vertexes, uses the two maps mentioned earlier to get airlines or airports from their code;
    // All read functions are now functional
    /*
    Statistics::getNumFlights(g);
    Statistics::getNumAirports(g);
    Statistics::getNumFlightsFromAirport(g, airportMap, "ORY");
    Statistics::getNumFlightsFromAirport(g, airportMap, "CDG");
    Statistics::getNumFlightsPerCity(g, cityMap, "Paris", "France");
    Statistics::getNumFlightsPerAirline(airlineMap, "IBE");
    Statistics::getNumFlightsFromAirportToDifferentCountries(g, airportMap, "JFK");
    Statistics::getNumFlightsFromCityToDifferentCountries(g, cityMap, "Paris", "France");

    Statistics::getNumOfReachableAirportsFromAirport(g, airportMap, "SSR");
    */

    welcomePage();


    return 0;

}
