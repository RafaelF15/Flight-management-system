//
// Created by André Santos on 29/12/2023.
//

#ifndef FLIGHT_MANAGEMENT_SYSTEM_INTERFACE_H
#define FLIGHT_MANAGEMENT_SYSTEM_INTERFACE_H

#include "Reading.h"
class Interface {

public:
    void welcomePage();

    void getStatistics();

    void globalStatistic();

    void exitProgram() const;
    void lastPage() const;


    Interface();
};


#endif //FLIGHT_MANAGEMENT_SYSTEM_INTERFACE_H
