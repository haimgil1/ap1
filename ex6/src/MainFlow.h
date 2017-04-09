
#ifndef TASK2BFS_MAINFLOW_H
#define TASK2BFS_MAINFLOW_H

#include <iostream>
#include <string.h>
#include "Cab.h"
#include "TripInformation.h"
#include "Driver.h"
#include "Passenger.h"
#include "TaxiCenter.h"
#include <stdexcept>
#include "Socket.h"
#include "Udp.h"
#include "InputValid.h"
#include "ThreadPool.h"

using namespace std;

class MainFlow {

private:
    Cab *cab;
    Driver *driver;
    TripInformation *tripInformation;
    Grid *map;
    double time;
    Socket *tcp;
    TaxiCenter *taxiCenter;
    int flagCase;
    int numOfDrivers;
    InputValid* inputValid;
    vector<Point> obstacles;
    int mapX,mapY;
    vector<string> inputByChar;
    Job *job;
    ThreadPool *threadpool;
    vector<pthread_t*> vecThreads;
public:
    // Default constructor.
    MainFlow(char *argv[]);

    // start the game to get the parameters and run the game.
    void startGame();

    // destructor.
    virtual ~MainFlow();

    // The function gets parameters and return a cab.
    Cab *cabParser(int cabId, int cabType, char manufacturer, char color1);

    // The function gets parameters and return a trip information.
    TripInformation *tripInfoParser(int tripId, int startX, int startY, int endX, int endY,
                                    int numOfPassengers, double tariff,
                                    Grid *map, int time);

    // The function gets parameters and return a map.
    Grid *MapParser(int n, int m);

    // The function send driver from the server to the client.
    void sendUpdateDriver(Driver *driver,int descriptor);

    // The function send cab from the server to the client.
    void sendUpdateCab(Cab *cab,int descriptor);

    // The function receive driver from the client.
    Driver* receiveDriver(int descriptor);

    // The function update the obstacle in the map.
    void updateObstacles();

    // Scan and checks if the map and the obstacles are valid.
    void scanMapAndObstacles();

    // Scan the cab and check if the cab if valid.
    void scanCab();

    // Scan the trip and check if the trip id valid.
    void scanTrip(int mapX, int mapY, Grid *map);

    // Scan and check the number of drivers.
    int scanNum();

    // The function resposible the manage of the thread of the clients.
    static void* handleThread(void* mainflow);
};


#endif //TASK2BFS_MAINFLOW_H
