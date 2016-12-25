cmake_minimum_required(VERSION 3.3)

project(EX2)


include(CTest)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
set(test_SRCS BfsTest.cpp CabTest.cpp DriverTest.cpp MatrixTest.cpp NodeTest.cpp PassengerTest.cpp
        PointTest.cpp TaxiCenterTest.cpp TripInfoTest.cpp MainFlowTest.cpp gtest.cpp)
add_executable(runUnitTests gtest.cpp ${test_SRCS})
target_link_libraries(runUnitTests gtest gmock core)
add_test(runUnitTests runUnitTests) 



