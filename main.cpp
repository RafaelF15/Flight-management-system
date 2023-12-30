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
void getApMethods();

void exitProgram();
void lastPage();
void credits();
Graph<Airport> g; //inicializei aqui porque não estava a reconhecer se fosse dentro do main
unordered_map<string, Airport> airportMap; //igual a cima

void welcomePage() {
    cout << endl << "=========WELCOME PAGE=========" << endl;
    cout << endl << "Options:\n\t1-Get statistics\n\t2-Airport methods\n\t5-Credits\n\te-Exit" <<endl;
    char input;
    while (true){
        cout << "Choose option:";
        cin >> input;

        switch (input) {
            case ('1'):
                getStatistics();
                return welcomePage();
            case ('2'):
                getApMethods();
                return welcomePage();
                 /*
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
    cout << endl << "Options:\n\t1-Global\n\tb-Back\n\te-Exit"<<endl;
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
void getApMethods(){
    cout << endl << "=========AIRPORT METHODS=========" << endl;
    cout << endl;
    cout << endl << "Choose the method:" << endl;
    cout << endl << "Options:\n\t1-Total flights from airport\n\t2-Total airlines from airport\n\tb-Back\n\te-Exit"<<endl;
    char option;
    int max;
    string code;
    while (true){
        cout << "Choose option:";
        cin >> option;
        switch (option) {
            case ('1'):
                cout << "Insert the airport code:" << endl;
                cin >> code;
                Statistics::getNumFlightsFromAirport(g, airportMap, code);
                lastPage();
                return getApMethods();
            case ('2'):
                cout << "Insert the airport code:" << endl;
                cin >> code;
                Statistics::getNumAirlinesFromAirport(g, airportMap, code);
                lastPage();
                return getApMethods();
                 /*
            case ('3'):
                cout << "Insert the airport code:" << endl;
                cin >> ap;
                if (d_.getAirports().find(ap) == d_.getAirports().end()){
                    cout << "\nNot a valid airport...\nTry again!\n\n";
                    getApMethods();
                }
                cout << "Number of city destinations: " << apm_.nCities(ap) << endl;
                lastPage();
                return getApMethods();
            case ('4'):
                cout << "Insert the airport code:" << endl;
                cin >> ap;
                if (d_.getAirports().find(ap) == d_.getAirports().end()){
                    cout << "\nNot a valid airport...\nTry again!\n\n";
                    getApMethods();
                }
                cout << "Number of country destinations: " << apm_.nCountries(ap) << endl;
                lastPage();
                return getApMethods();
            case ('5'):
                cout << "Insert the origin airport code:" << endl;
                cin >> ap;
                if (d_.getAirports().find(ap) == d_.getAirports().end()){
                    cout << "\nNot a valid airport...\nTry again!\n\n";
                    getApMethods();
                }
                cout << "Insert the maximum number of flights:" << endl;
                cin >> max;
                cout << "Number of reachable airports: " << apm_.nAirportsWithMaxFlights(ap,max) << endl;
                lastPage();
                return getApMethods();
            case ('6'):
                cout << "Insert the origin airport code:" << endl;
                cin >> ap;
                if (d_.getAirports().find(ap) == d_.getAirports().end()){
                    cout << "\nNot a valid airport...\nTry again!\n\n";
                    getApMethods();
                }
                cout << "Insert the maximum number of flights:" << endl;
                cin >> max;
                cout << "Number of reachable cities: " << apm_.nCitiesWithMaxFlights(ap,max) << endl;
                lastPage();
                return getApMethods();
            case ('7'):
                cout << "Insert the origin airport code:" << endl;
                cin >> ap;
                if (d_.getAirports().find(ap) == d_.getAirports().end()){
                    cout << "\nNot a valid airport...\nTry again!\n\n";
                    getApMethods();
                }
                cout << "Insert the maximum number of flights:" << endl;
                cin >> max;
                cout << "Number of reachable countries: " << apm_.nCountriesWithMaxFlights(ap,max) << endl;
                lastPage();
                return getApMethods();
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
    // unordered_map<string, Airport> airportMap; Find airport by code
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
    Statistics::getNumOfReachableCitiesFromAirport(g, airportMap, "SSR");
    Statistics::getNumOfReachableCountriesFromAirport(g, airportMap, "SSR");

    Statistics::numReachableAirportsXFlights(g, airportMap, "SSR", 2);
    Statistics::numReachableCitiesXFlights(g, airportMap,"SSR", 2);
    Statistics::numReachableCountriesXFlights(g, airportMap,"SSR", 2);

    */

    welcomePage();


    return 0;


}
