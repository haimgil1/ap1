cmake_minimum_required(VERSION 3.6)
project(EX2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x ")

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(SOURCE_FILES main.cpp src/Bfs.cpp src/Bfs.h src/Node.cpp src/Node.h src/Point.cpp src/Point.h
        src/Grid.h src/Matrix.cpp src/Matrix.h src/AbstractNode.cpp src/AbstractNode.h src/Cab.cpp
        src/Cab.h src/LuxuryCab.cpp src/LuxuryCab.h src/CarManufacturer.h src/Color.h src/StandardCab.cpp
        src/StandardCab.h src/FactoryCab.cpp src/FactoryCab.h Tests/CabTest.cpp Tests/CabTest.cpp
        Tests/Defines.h src/Driver.cpp src/Driver.h src/MaritalStatus.h src/Passenger.cpp src/Passenger.h
        src/TripInformation.cpp src/TripInformation.h Tests/DriverTest.cpp Tests/PassengerTest.cpp
        Tests/TripInfoTest.cpp Tests/NodeTest.cpp src/TaxiCenter.cpp src/TaxiCenter.h Tests/MatrixTest.cpp
        Tests/BfsTest.cpp Tests/TaxiCenterTest.cpp Tests/PointTest.cpp src/MainFlow.cpp src/MainFlow.h
        src/Grid.cpp src/Searchable.cpp src/Searchable.h Tests/MainFlowTest.cpp)
add_executable(EX2 ${SOURCE_FILES} Tests/CabTest.cpp Tests/CabTest.cpp src/Driver.cpp src/Driver.h
        src/MaritalStatus.h src/Passenger.cpp src/Passenger.h src/TripInformation.cpp
        src/TripInformation.h Tests/DriverTest.cpp Tests/PassengerTest.cpp Tests/TripInfoTest.cpp
        Tests/NodeTest.cpp src/TaxiCenter.cpp src/TaxiCenter.h Tests/PointTest.cpp src/MainFlow.cpp
        src/MainFlow.h src/Grid.cpp Tests/MainFlowTest.cpp)
target_link_libraries(EX2 gtest gtest_main)


