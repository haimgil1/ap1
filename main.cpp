#include <iostream>
#include <stdio.h>
#include "src/MainFlow.h"
#include <stdexcept>
#include <gtest/gtest.h>

using namespace std;
// A main class.
int main(int argc, char *argv[]) {
    MainFlow mainFlow;
    try {
        //mainFlow.startGame();
    } catch (std::invalid_argument &err){
        cout << err.what();
    }

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
