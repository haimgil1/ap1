#include <iostream>
#include "MainFlow.h"

using namespace std;
using namespace boost::iostreams;
using namespace boost::archive;

int main(int argc, char *argv[]) {
    MainFlow mainFlow(argv);
    try {
        mainFlow.startGame();
    } catch (std::invalid_argument &err) {
        cout << err.what();
    }
    return 0;
}