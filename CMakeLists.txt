cmake_minimum_required(VERSION 3.26)
project(Flight_management_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(Flight_management_system main.cpp
        Airport.h
        Airport.cpp
        Airline.cpp
        Airline.h
        Flight.cpp
        Flight.h
        City.cpp
        City.h
        Graph.h
        Reading.cpp
        Reading.h)
