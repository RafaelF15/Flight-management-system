#include <iostream>
#include "Graph.h"
#include "Airline.h"
#include "Airport.h"
#include "City.h"
#include "Flight.h"
#include "Reading.h"
#include "Statistics.h"
#include <unordered_map>
#include <typeinfo>
using namespace std;

void welcomePage();

void getStatistics();

void globalStatistic();
void cityStatistic();
void airlineStatistic();
void airportStatistic();
void getApMethods();
void otherInfo();
void exitProgram();
void lastPage();
void credits();
Graph<Airport> g; //inicializei aqui porque não estava a reconhecer se fosse dentro do main
unordered_map<string, Airport> airportMap; //igual a cima
unordered_map<string, City> cityMap; //same
unordered_map<string, Airline> airlineMap; //igual

void welcomePage() {
    cout << endl << "=========WELCOME PAGE=========" << endl;
    //cout << Statistics::getNumFlightsFromCityToDifferentCountries(g,cityMap,"Porto","Portugal");
    cout << endl << "Options:\n\t1-Get statistics\n\t2-Airport methods\n\t3-Other methods\n\t5-Credits\n\te-Exit" <<endl;
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
            case ('3'):
                otherInfo();
                return welcomePage();
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
    cout << "Choose the type of statistics!" << endl;
    cout << endl << "Options:\n\t1-Global\n\t2-City\n\t3-Airline\n\t4-Airport\n\tb-Back\n\te-Exit"<<endl;
    char inputType;
    string inputDestination;
    while (true){
        cout << "Choose option:";
        cin >> inputType;
        switch (inputType) {
            case ('1'):
                globalStatistic();
                return getStatistics();
           case ('2'):
               cityStatistic();
               return getStatistics();
           case ('3'):
               airlineStatistic();
               return getStatistics();
           case ('4'):
               airportStatistic();
               return getStatistics();
                     /*
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
    cout << "Choose the statistic!" << endl;
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
                return getStatistics();
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
void cityStatistic(){
    cout << endl << "=========CITY STATISTICS=========" << endl;
    cout << endl;
    string city;
    string country;
    cout << "Insert the name of the city: "<< endl;
    getline(cin>>ws, city);
    cout << "Insert the country of the city you have chosen: " << endl;
    getline(cin>>ws, country);
    auto it= cityMap.find(city + country);
    if (it == cityMap.end()) {
        cout << "The city inserted <" << city << "," << country << "> is not valid. Try again!" << endl;
        cityStatistic();
    }
    cout << "Choose the statistic!" << endl;
    cout << endl << "Options:\n\t1-Total flights\n\t2-Number of flights to different countries\n\tb-Back\n\te-Exit" << endl;

    char option;
    while (true){
        cout << "Choose option:";
        cin >> option;
        switch (option) {
            case ('1'):
                Statistics::getNumFlightsPerCity(g,cityMap,city,country);
                lastPage();
                return getStatistics();
            case ('2'):
                Statistics::getNumFlightsFromCityToDifferentCountries(g,cityMap,city,country);
                lastPage();
                return getStatistics();
                 /*
            case ('3'):
                cout << "Number of airlines: " <<  d_.nAirlines2(c) << endl;
                lastPage();
                return getStatistics();
            case ('4'):
                cout << "Number of destinations: " << d_.nDestinations2(c) << endl;
                lastPage();
                return getStatistics();
                 */
            case ('b'):
                return getStatistics();
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
void airlineStatistic(){
    cout << endl << "=========AIRLINE STATISTICS=========" << endl;
    cout << endl;
    cout << "Insert the code of the airline:" << endl;
    string code;
    cin >> code;
    auto it= airlineMap.find(code);
    if (it == airlineMap.end()) {
        cout << "The airline with code <" << code << "> does not exist. Try again!" << endl;
        airlineStatistic();
    }
    cout << "Choose the statistic!" << endl;
    cout << endl << "Options:\n\t1-Total flights\n\tb-Back\n\te-Exit"<<endl;

    char option;
    while (true){
        cout << "Choose option:";
        cin >> option;
        switch (option) {
            case ('1'):
                Statistics::getNumFlightsPerAirline(airlineMap, code);
                lastPage();
                return getStatistics();
            case ('b'):
                return getStatistics();
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
void airportStatistic(){
    cout << endl << "=========AIRPORT STATISTICS=========" << endl;
    cout << endl;
    string code;
    cout << "Insert the airport code:" << endl;
    cin >> code;
    auto it= airportMap.find(code);
    if (it == airportMap.end()) {
        cout << "The airport with code <" << code << "> does not exist. Try again!" << endl;
        airportStatistic();
    }
    cout << endl << "Choose the statistic!" << endl;
    cout << endl << "Options:\n\t1-Number of flights to different countries\n\tb-Back\n\te-Exit"<<endl;

    char option;

    while (true){
        cout << "Choose option:";
        cin >> option;

        switch (option) {
            case ('1'):
                Statistics::getNumFlightsFromAirportToDifferentCountries(g,airportMap,code);
                lastPage();
                return getStatistics();
            case ('b'):
                return getStatistics();
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
    cout << endl << "Choose the method!" << endl;
    cout << endl << "Options:\n\t1-Total flights from airport\n\t2-Total airlines from airport\n\t3-Total airport destinations from airport\n\t4-Total city destinations from airport\n\t5-Total country destinations from airport\n\t6-Number of reachable airports with maximum of X stops from airport\n\t7-Number of reachable cities with maximum of X stops from airport\n\t8-Number of reachable countries with maximum of X stops from airport\n\tb-Back\n\te-Exit"<<endl;
    char option;
    string max;
    string code;
    auto it = airportMap.find(code);
    while (true){
        cout << "Choose option:";
        cin >> option;
        switch (option) {
            case ('1'):
                cout << "Insert the airport code:" << endl;
                cin >> code;
                it = airportMap.find(code);
                if (it == airportMap.end()) {
                    cout << "There is no Airport with code <" << code << "> Try again!" << endl;
                    getApMethods();
                }
                Statistics::getNumFlightsFromAirport(g, airportMap, code);
                lastPage();
                return getApMethods();
            case ('2'):
                cout << "Insert the airport code:" << endl;
                cin >> code;
                it = airportMap.find(code);
                if (it == airportMap.end()) {
                    cout << "There is no Airport with code <" << code << "> Try again!" << endl;
                    getApMethods();
                }
                Statistics::getNumAirlinesFromAirport(g, airportMap, code);
                lastPage();
                return getApMethods();
            case ('3'):
                cout << "Insert the airport code:" << endl;
                cin >> code;
                it = airportMap.find(code);
                if (it == airportMap.end()) {
                    cout << "There is no Airport with code <" << code << "> Try again!" << endl;
                    getApMethods();
                }
                Statistics::getNumOfReachableAirportsFromAirport(g,airportMap,code);
                lastPage();
                return getApMethods();
            case ('4'):
                cout << "Insert the airport code:" << endl;
                cin >> code;
                it = airportMap.find(code);
                if (it == airportMap.end()) {
                    cout << "There is no Airport with code <" << code << "> Try again!" << endl;
                    getApMethods();
                }
                //completar com função
                lastPage();
                return getApMethods();
            case ('5'):
                cout << "Insert the airport code:" << endl;
                cin >> code;
                it = airportMap.find(code);
                if (it == airportMap.end()) {
                    cout << "There is no Airport with code <" << code << "> Try again!" << endl;
                    getApMethods();
                }
                //completar com função
                lastPage();
                return getApMethods();
            case ('6'):
                int max1;
                cout << "Insert the origin airport code:" << endl;
                cin >> code;
                it = airportMap.find(code);
                if (it == airportMap.end()) {
                    cout << "There is no Airport with code <" << code << "> Try again!" << endl;
                    getApMethods();
                }
                try {
                    cout << "Insert the maximum number of stops:" << endl; // or flights?
                    cin >> max;
                    max1 = stoi(max);
                } catch (const invalid_argument& ia) {
                    cerr << " Insert an integer, please. Try again! "<< endl;
                    getApMethods();
                }
                Statistics::numReachableAirportsXFlights(g,airportMap,code,max1);
                lastPage();
                return getApMethods();
            case ('7'):
                int max2;
                cout << "Insert the origin airport code:" << endl;
                cin >> code;
                it = airportMap.find(code);
                if (it == airportMap.end()) {
                    cout << "There is no Airport with code <" << code << "> Try again!" << endl;
                    getApMethods();
                }
                try {
                    cout << "Insert the maximum number of stops:" << endl; // or flights?
                    cin >> max;
                    max2 = stoi(max);
                } catch (const invalid_argument& ia) {
                    cerr << " Insert an integer, please. Try again! "<< endl;
                    getApMethods();
                }
                Statistics::numReachableCitiesXFlights(g,airportMap,code,max2);
                lastPage();
                return getApMethods();
            case ('8'):
                int max3;
                cout << "Insert the origin airport code:" << endl;
                cin >> code;
                it = airportMap.find(code);
                if (it == airportMap.end()) {
                    cout << "There is no Airport with code <" << code << "> Try again!" << endl;
                    getApMethods();
                }
                try {
                    cout << "Insert the maximum number of stops:" << endl; // or flights?
                    cin >> max;
                    max3 = stoi(max);
                } catch (const invalid_argument& ia) {
                    cerr << " Insert an integer, please. Try again! "<< endl;
                    getApMethods();
                }
                Statistics::numReachableCountriesXFlights(g,airportMap,code,max3);
                lastPage();
                return getApMethods();
            case ('b'):
                return welcomePage();
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
void otherInfo(){
    cout << endl << "=========OTHER INFORMATIONS=========" << endl;
    cout << endl;

    cout << endl << "Chose the method!" << endl;
    cout << endl << "Options:\n\t1-Airports with top-K number of flights\n\tb-Back\n\te-Exit"<<endl;

    char option;
    string k;
    while (true){
        cout << "Choose option:";
        cin >> option;

        switch (option) {
            case ('1'):
                int k1;
                try {
                    cout << "How many airports with most flights?" << endl;
                    cin >> k;
                    k1 = stoi(k);
                } catch (const invalid_argument& ia) {
                    cerr << " Insert an integer, please. Try again! "<< endl;
                    otherInfo();
                }
                Statistics::getTopAirportsByFlights(g,k1);
                lastPage();
                return otherInfo();
                /*
            case ('2'):
                cout << "How many airports with most flights?";
                cin >> k;
                cout << "Top-" << k << " airports with most flights: " ;
                for (auto a: d_.topKairports(stoi(k))){
                    cout << a << " | " ;
                }
                cout << endl;
                lastPage();
                return otherInfo();
            case ('3'):
                cout << "Do you want an airline filter?" << endl;
                cout << endl << "Options:\n\t1-Yes\n\t2-No\n\t" <<endl;
                char yn;
                while(flag3) {
                    cout << "Choose option:";
                    cin >> yn;
                    switch (yn) {
                        case ('1'):
                            filters = createVec();
                            flag3 = 0;
                            break;
                        case ('2'):
                            flag3 = 0;
                            break;
                        default:
                            cout << "Not a valid option." << endl;
                    }
                }
                d_.printArtPoints(filters);
                lastPage();
                return otherInfo();
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
    //unordered_map<string, City> cityMap;
    //IMPORTANT : whenever using the citymap, the keys are of the following format: "ParisFrance"  There are multiple cities with the same name in different countries;
    //You can just use string concatenation: Key = city + country;
    // unordered_map<string, Airline> airlineMap; // Find airline by code
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

    //Statistics::findDiameter(g);
    Statistics::articulationPoints(&g);
    Statistics::numReachableCitiesXFlights(g, airportMap,"SSR", 2);
    Statistics::numReachableCountriesXFlights(g, airportMap,"SSR", 2);

    vector<string> topAirports = Statistics::getTopAirportsByFlights(g, 5);

    */
    //Statistics::articulationPoints(&g, airportMap);

    welcomePage();


    return 0;

}
