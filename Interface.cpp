//
// Created by André Santos on 29/12/2023.
//
#include <iostream>
#include <regex>
#include "Interface.h"
#include "Statistics.h"

using namespace std;

Interface::Interface() = default;


void Interface::welcomePage() {
    cout << endl << "=========WELCOME PAGE=========" << endl;
    cout << endl << "Options:\n\t1-Get flights\n\t2-Get statistics\n\t3-Airport methods\n\t4-Other informations\n\t5-Credits\n\te-Exit"<<endl;
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
            case ('5'):
                credits();
                return welcomePage();
                 */
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;

        }
    }
}

void Interface::getStatistics(){
    cout << endl << "=========GET STATISTICS=========" << endl;
    cout << endl;
    cout << "Choose the type of statistics:" << endl;
    cout << endl << "Options:\n\t1-Global\n\t2-Country\n\t3-City\n\t4-Airline\n\t5-Airport\n\tb-Back\n\te-Exit"<<endl;
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
                countryStatistic();
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
void Interface::globalStatistic(){
    cout << endl << "=========GLOBAL STATISTICS=========" << endl;
    cout << endl;
    cout << "Choose the statistic:" << endl;
    cout << endl << "Options:\n\t1-Total airports\n\t2-Total cities\n\t3-Total countries\n\t4-Total airlines\n\t5-Total flights\n\tb-Back\n\te-Exit"<<endl;

    char option;
    while (true){
        cout << "Choose option:";
        cin >> option;
        switch (option) {
            case ('1'):
                //cout << "Number of airports: " << Statistics::getNumAirports()<< endl;
                lastPage();
                return getStatistics();
            case ('2'):
                // cout << "Number of flights: " << d_.totalFlights() << endl;
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

void Interface::lastPage() const {
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

void Interface::exitProgram() const {
    cout << endl << "Exiting program..." << endl;
    throw 200;
}



