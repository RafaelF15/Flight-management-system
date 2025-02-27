#include <iostream>
#include "Graph.h"
#include "Airline.h"
#include "Airport.h"
#include "City.h"
#include "Flight.h"
#include "Reading.h"
#include "Statistics.h"
#include <unordered_map>


using namespace std;

void welcomePage();
void getStatistics();
void globalStatistic();
void cityStatistic();
void airlineStatistic();
void getApMethods();
void otherInfo();
void search();
void getFlights();
void exitProgram();
void lastPage();
void credits();
Graph<Airport> g;
unordered_map<string, Airport> airportMap;
unordered_map<string, City> cityMap;
unordered_map<string, Airline> airlineMap;

void welcomePage() {
    cout << endl << "=========WELCOME PAGE=========" << endl;
    cout << endl << "Options:\n\t1-Get flights\n\t2-Get statistics\n\t3-Airport methods\n\t4-Other methods\n\t5-Search\n\t6-Credits\n\te-Exit" <<endl;
    char input;
    while (true){
        cout << "Choose option:";
        cin >> input;

        switch (input) {
            case ('1'):
                getFlights();
                return welcomePage();
            case ('2'):
                getStatistics();
                return welcomePage();
            case ('3'):
                getApMethods();
                return welcomePage();
            case ('4'):
                otherInfo();
                return welcomePage();
            case ('5'):
                search();
                return welcomePage();
            case ('6'):
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
    cout << endl << "Options:\n\t1-Global\n\t2-City\n\t3-Airline\n\tb-Back\n\te-Exit"<<endl;
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
    cout << endl << "Options:\n\t1-Total flights\n\t2-Number of different countries reachable from airport\n\tb-Back\n\te-Exit" << endl;

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

void getApMethods(){
    cout << endl << "=========AIRPORT METHODS=========" << endl;
    cout << endl;
    cout << endl << "Choose the method!" << endl;
    cout << endl << "Options:\n\t1-Total flights from airport\n\t2-Total airlines from airport\n\t3-Total airport destinations from airport\n\t4-Total city destinations from airport\n\t5-Total country destinations from airport\n\t6-Number of reachable airports with maximum of X stops from airport\n\t7-Number of reachable cities with maximum of X stops from airport\n\t8-Number of reachable countries with maximum of X stops from airport\n\t9-Number of flights to different countries\n\tb-Back\n\te-Exit"<<endl;
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
                Statistics::getNumOfReachableCitiesFromAirport(g,airportMap,code);
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
                Statistics::getNumOfReachableCountriesFromAirport(g,airportMap,code);
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
            case ('9'):
                cout << "Insert the airport code:" << endl;
                cin >> code;
                it = airportMap.find(code);
                if (it == airportMap.end()) {
                    cout << "There is no Airport with code <" << code << "> Try again!" << endl;
                    getApMethods();
                }
                Statistics::getNumFlightsFromAirportToDifferentCountries(g,airportMap,code);
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
    cout << endl << "Options:\n\t1-Airports with top-K number of flights\n\t2-Articulation points\n\t3-Maximum trip\n\tb-Back\n\te-Exit"<<endl;
    Graph<Airport> g1 = g;
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
            case ('2'):
                for(Vertex<Airport>* v : g1.getVertexSet()){
                    for(Edge<Airport> e : v->getAdj()){
                        Flight t(e.getDest()->getInfo(), v->getInfo(), e.getFlight().getAirline());
                        g1.addEdge(e.getDest()->getInfo(), v->getInfo(), t);
                    }
                }
                Statistics::articulationPoints(&g1,airportMap);
                lastPage();
                return otherInfo();
            case ('3'):
                Statistics::findDiameter(g);
                lastPage();
                return otherInfo();
            case ('b'):
                return welcomePage();
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}

void search(){
    cout << endl << "=========SEARCH MENU=========" << endl;
    cout << endl;

    cout << endl << "Chose the method!" << endl;
    cout << endl << "Options:\n\t1-Get airport info from code\n\t2-Get airline info from code\n\t3-List all airports from a specific city\n\tb-Back\n\te-Exit"<<endl;
    char option;
    string code;
    string city;
    string country;
    auto it = airportMap.find(code);
    auto it1 = airlineMap.find(code);
    auto it2 = cityMap.find(city+country);
    while (true){
        cout << "Choose option:";
        cin >> option;

        switch (option) {
            case ('1'):
                cout << "Insert the airport code:" << endl;
                cin >> code;
                it = airportMap.find(code);
                if (it == airportMap.end()) {
                    cout << "There is no airport with code <" << code << "> Try again!" << endl;
                    search();
                }
                cout << "The airport name with code <" << code << "> is " << it->second.getName() << ", it is located in " << it->second.getCity() << ", " << it->second.getCountry() << ".";
                lastPage();
                return search();
            case ('2'):
                cout << "Insert the airline code:" << endl;
                cin >> code;
                it1 = airlineMap.find(code);
                if (it1 == airlineMap.end()) {
                    cout << "There is no airline with code <" << code << "> Try again!" << endl;
                    search();
                }
                cout << "The airline name with code <" << code << "> is " << it1->second.getName() << " and it is from " << it1->second.getCountry() << ".";
                lastPage();
                return search();
            case ('3'):
                cout << "Insert the name of the city: "<< endl;
                getline(cin>>ws, city);
                cout << "Insert the country of the city you have chosen: " << endl;
                getline(cin>>ws, country);
                it2 = cityMap.find(city + country);
                if (it2 == cityMap.end()) {
                    cout << "The city inserted <" << city << "," << country << "> is not valid. Try again!" << endl;
                    search();
                }
                cout << endl;
                cout << "There is a total of " << it2->second.getAirports().size() << " airports in the city " << city << ", " << country << "." << endl;
                cout << "Here's the list of airports: " << endl;
                cout << "|";
                for (Airport a: it2->second.getAirports()){
                    cout << a.getName() << "|";
                };
                lastPage();
                return search();
            case ('b'):
                return welcomePage();
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
void getFlights() {
    cout << endl << "=========GET FLIGHTS=========" << endl;
    cout << endl;
    char yn;
    cout << "Here you can search for the best flights!" << endl;
    cout << "Do you want to exclude any specific airline?";
    cout << endl << "Options:\n1-Yes\n2-No\n";
    cin >> yn;
    unordered_set<string> excludedAirlines;
    if (yn == '1') {
        string input;
        cout << "Type the code of the airlines you want to exclude, separated by ',' (example: MAU,MDG)" << endl;
        cin >> input;

        std::string codigo;
        for (char c : input) {
            if (c != ',') {
                codigo += c;
            } else if (codigo.length() == 3) {
                excludedAirlines.insert(codigo);
                codigo = "";
            }
        }

        if (codigo.length() == 3) {
            excludedAirlines.insert(codigo);
        }
        for (char c : input) {
            if (!isalpha(c) and c != ','){
                cout << "There is probably an error in your input format. Try again!";
                getFlights();
            }
        }
        for (const auto& code : excludedAirlines) {
            auto it = airlineMap.find(code);
            if (it == airlineMap.end()) {
                cout << "You typed invalid airlines. For example, there is no airline with code <" << codigo << "> Try again!" << endl;
                getFlights();
            }
        }
    }
    else if (yn == '2') {
        excludedAirlines = {};
    }
    else {
        cout << "Invalid input. Try again!";
        getFlights();
    }

    cout << "Choose the type of origin:" << endl;
    cout << endl << "Options:\n\t1-Airport\n\t2-City\n\tb-Back\n\te-Exit"<<endl;
    int flag = 1;
    char inputTypeO;
    string code;
    string city;
    string country;
    auto it = airportMap.find(code);
    auto it1 = cityMap.find(city+country);
    string inputOrigin;
    string source_a;
    string dest_a;
    string source_c;
    string dest_c;
    string source_p;
    string dest_p;
    int a;
    while (flag){
        cout << "Choose option:";
        cin >> inputTypeO;
        switch (inputTypeO) {
            case ('1'):
                cout << "Insert the origin airport code:" << endl;
                cin >> source_a;
                it = airportMap.find(source_a);
                if (it == airportMap.end()) {
                    cout << "There is no airport with code <" << source_a << "> Try again!" << endl;
                    getFlights();
                }
                a = 0;
                flag = 0;
                break;
            case ('2'):
                cout << "Insert the name of the origin city: "<< endl;
                getline(cin>>ws, source_c);
                cout << "Insert the country of the city you have chosen: " << endl;
                getline(cin>>ws, source_p);
                it1 = cityMap.find(source_c + source_p);
                if (it1 == cityMap.end()) {
                    cout << "The city inserted <" << source_c << "," << source_p << "> is not valid. Try again!" << endl;
                    getFlights();
                }
                a = 1;
                flag = 0;
                break;
            case ('b'):
                return welcomePage();

            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }

    cout << endl;
    cout << "Choose the type of destination:" << endl;
    cout << endl << "Options:\n\t1-Airport\n\t2-City\n\tb-Back\n\te-Exit"<<endl;

    auto it2 = airportMap.find(source_a);
    auto it3 = cityMap.find(city+country);
    auto it4 = airportMap.find(dest_a);
    auto it5 = cityMap.find(city+country);
    char inputTypeD;
    string cityb;
    string countryb;
    string inputDestination;
    string citya;
    string countrya;


    int flag2 = 1;
    while (flag2){
        cout << "Choose option:";
        cin >> inputTypeD;
        switch (inputTypeD) {
            case ('1'):
                cout << "Insert the destination airport code:" << endl;
                cin >> dest_a;
                it = airportMap.find(dest_a);
                if (it == airportMap.end()) {
                    cout << "There is no airport with code <" << dest_a << "> Try again!" << endl;
                    getFlights();
                }
                if (a==0) {
                    it2 = airportMap.find(source_a);
                    it4 = airportMap.find(dest_a);
                    citya = it2->second.getCity();
                    countrya = it2->second.getCountry();
                    cityb = it4->second.getCity();
                    countryb = it4->second.getCountry();
                    Statistics::bestFlightAirportToAirport(g,source_a,dest_a,airportMap,excludedAirlines);
                    it3 = cityMap.find(citya+countrya);
                    it5 = cityMap.find(cityb+countryb);
                    if (it2->second == it4->second) {
                        cout << "You cannot find a flight to the same place of origin. Try again!";
                    }
                    else if (source_a == dest_a) {
                        cout << "You cannot find a flight to the same place of origin. Try again!";
                    }
                    excludedAirlines = {};
                }
                else if (a==1) {
                    Statistics::bestFlightCityToAirport(g,source_c,source_p, dest_a,cityMap, airportMap, excludedAirlines);
                    it3 = cityMap.find(source_c+source_p);
                    it2 = airportMap.find(dest_a);
                    citya = it2->second.getCity();
                    countrya = it2->second.getCountry();
                    it5 = cityMap.find(citya+countrya);
                    if (it3->second.getAirports()[0] == it2->second ) {
                        cout << "You cannot find a flight to the same place of origin. Try again!";
                    }
                    else if (it2->second.getCity() + it2->second.getCountry() == source_c+source_p){
                        cout << "You cannot find a flight to the same place of origin. Try again!";
                    }
                    excludedAirlines = {};
                }
                lastPage();
                return getFlights();
            case ('2'):
                cout << "Insert the name of the destination city: "<< endl;
                getline(cin>>ws, dest_c);
                cout << "Insert the country of the city you have chosen: " << endl;
                getline(cin>>ws, dest_p);
                it1 = cityMap.find(dest_c + dest_p);
                if (it1 == cityMap.end()) {
                    cout << "The city inserted <" << dest_c << "," << dest_p << "> is not valid. Try again!" << endl;
                    getFlights();
                }
                if (a==0) {
                    Statistics::bestFlightAirportToCity(g,source_a,dest_c,dest_p,cityMap,airportMap,excludedAirlines);
                    it3 = cityMap.find(dest_c+dest_p);
                    it2 = airportMap.find(source_a);
                    citya = it2->second.getCity();
                    countrya = it2->second.getCountry();
                    it5 = cityMap.find(citya+countrya);
                    if (it3->second.getAirports()[0] == it2->second and it3->second.getAirports().size() == 1 and it5->second.getAirports().size()==1) {
                        cout << "You cannot find a flight to the same place of origin. Try again!";
                    }
                    excludedAirlines = {};
                }
                else if (a==1){
                    Statistics::bestFlightCityToCity(g,source_c,source_p,dest_c,dest_p,cityMap,airportMap,excludedAirlines);
                    it3 = cityMap.find(source_c+source_p);
                    it5 = cityMap.find(dest_c+dest_p);
                    if (it3->second.getAirports()[0] == it5->second.getAirports()[0] and it3->second.getAirports().size() == 1 and it5->second.getAirports().size()==1) {
                        cout << "You cannot find a flight to the same place of origin. Try again!";
                    }
                    excludedAirlines = {};
                }
                lastPage();
                return welcomePage();
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
    cout << endl;
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
    cout << "Andre Santos, up202207724" << endl; //ver problema dos acentos com outros pcs
    cout << "Iara Bras, up202208825" << endl; //mesmo que em cima
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
    Reading::readAirports(g, airportMap,
                          cityMap); // Reads airports from files and adds them to the graph as vertexes (also puts them in the airline map for fast searching if needed)
    Reading::readAirlines(airlineMap); // Reads airlines and puts them on the airline map for fast searching if needed
    Reading::readFlights(g, airportMap,
                         airlineMap); // Reads flights from the file, adds them to the graph as vertexes, uses the two maps mentioned earlier to get airlines or airports from their code;

    welcomePage();

    return 0;

}
