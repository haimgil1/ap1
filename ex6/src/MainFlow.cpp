
#include "MainFlow.h"
#include "FactoryCab.h"
#include "Tcp.h"
#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP
using namespace std;
using namespace boost::iostreams;
using namespace boost::archive;

pthread_mutex_t clientLock = PTHREAD_MUTEX_INITIALIZER;

MainFlow::MainFlow(char *argv[]) {
    this->cab = NULL;
    this->driver = NULL;
    this->tripInformation = NULL;
    this->map = NULL;
    this->tcp = NULL;
    this->taxiCenter = NULL;
    this->time = 0;
    this->tcp = new Tcp(1, atoi(argv[1])); // Set the port to tcp.
    this->flagCase = 0;
    this->tcp->initialize();
    this->inputValid = new InputValid("");
    this->threadpool = new ThreadPool(5);
}

MainFlow::~MainFlow() {

    delete tcp;
    delete map;
    delete taxiCenter;
    delete inputValid;
    delete threadpool;
    for(int i=0; i< (int)vecThreads.size(); i++) {
      delete vecThreads[i];
      }
}

void MainFlow::startGame() {
    int driverId;
    scanMapAndObstacles();
    taxiCenter = new TaxiCenter(this->map); // Create taxi center.
    int mission; // the num of choice in the menu.
    do {
        cin >> mission;
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (mission) {

            case 1:  // Get driver parameters.
            {
                //cin >> numOfDrivers;
                //int sizeDrivers = scanNumOfDrivers();
                this->numOfDrivers = scanNum();
                if (numOfDrivers < 0) {
                    break;
                }
                for (int i = 0; i < numOfDrivers; i++) { // Getting the drivers.
                    pthread_t *t1 = new pthread_t();
                    int status = pthread_create(t1, NULL, handleThread, (void *) this);
                    if (status) {
                        LINFO << "thread not create\n";
                    }
                    LINFO << "create thread client\n";
                    vecThreads.push_back(t1);
                }
                break;
            }
            case 2:  // Get trip parameters.
                this->scanTrip(this->mapX, this->mapY, this->map);
                break;

            case 3: // Get cab parameters.
                scanCab();
                break;

            case 9:
                // Start the trips.
                this->time++;

                // Waiting for all connection.
                while (true) {
                    if (this->numOfDrivers <= 0) {
                        break;
                    }
                }

                // Make one step and send the update driver to the client.
                taxiCenter->driving(this->time);
                this->flagCase = 9;
                break;

            case 4:
                // Print driver location
                //cin >> driverId;
                driverId = scanNum();
                if (driverId < 0) {
                    break;
                }
                taxiCenter->printDriverLocation(driverId);
                this->flagCase = 4;
                break;
            case 7:
              
                this->driver = taxiCenter->getDriverVec()[0];
                for (int i = 0; i < (int) taxiCenter->getDriverVec().size(); i++) {
                    this->driver->setId(-1); // Prepare to end the client.
                    sendUpdateDriver(this->driver, taxiCenter->getDescriptors()[i]);
                }
                this->flagCase = 7;
                this->threadpool->terminate();
                 
                LINFO << "finish terminate\n";
                // Close the pthread of the clients.
                for(int j=0; j< (int) this->vecThreads.size(); j++) {
                    pthread_join(*(this->vecThreads[j]), NULL);
                    }
                return;
            default:
                cout << "-1\n";
                LINFO << "invalid number of mission\n";
        }
    } while (mission != 7);
}

Cab *MainFlow::cabParser(int cabId, int cabType, char manufacturer, char color1) {
    CarManufacturer carManufacturer = CarManufacturer(manufacturer);
    Color color = Color(color1);
    FactoryCab factoryCab;
    return factoryCab.getCab(cabType, cabId, carManufacturer, color);
}


TripInformation *MainFlow::tripInfoParser(int tripId, int startX, int startY, int endX, int endY,
                                          int numOfPassengers, double tariff,
                                          Grid *map, int time) {
    Point startP(startX, startY);
    Point endP(endX, endY);
    return new TripInformation(tripId, startP, endP, numOfPassengers, tariff, map, time);
}

Grid *MainFlow::MapParser(int n, int m) {
    return new Matrix(n, m);
}

void MainFlow::sendUpdateDriver(Driver *driver, int descriptor) {
    string serial_str;
    back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    binary_oarchive oa(s);
    oa << driver;
    s.flush();
    tcp->sendData(serial_str, descriptor);
}

void MainFlow::sendUpdateCab(Cab *cab, int descriptor) {
    string serial_str;
    back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    binary_oarchive oa(s);
    oa << cab;
    s.flush();
    tcp->sendData(serial_str, descriptor);

}

Driver *MainFlow::receiveDriver(int descriptor) {
    char buffer[65000];
    tcp->reciveData(buffer, sizeof(buffer), descriptor);
    char *end = buffer + 64999;
    basic_array_source<char> device(buffer, end);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    binary_iarchive ia(s2);
    ia >> this->driver;
    // update the current point to the driver.
    delete this->driver->getcurrentPoint();
    this->driver->setCurrentPoint(this->map->getSourceElement(0, 0));
    return this->driver;
}

void MainFlow::updateObstacles() {
    char dummy;
    int numOfObstacles;
    cin >> numOfObstacles; // Get number of obstacles.
    while (numOfObstacles > 0) { // Get the points of the obstacles.
        int px, py;
        cin >> px >> dummy >> py;
        this->map->getSourceElement(px, py)->setObstacle(true);
        numOfObstacles--;
    }
}


void *MainFlow::handleThread(void *mainflow) {
    //Create special descriptor for every client.
    MainFlow *mainFlow = (MainFlow *) mainflow;
    LINFO << "before connection\n";
    int descriptor = mainFlow->tcp->acceptDescriptorCommunicate();
    LINFO << "after connection\n";

    // Receive driver and his cab to the server.
    pthread_mutex_lock(&clientLock);
    Driver *driver = mainFlow->receiveDriver(descriptor); // Receive the driver from client.
    mainFlow->cab = mainFlow->taxiCenter->findCabById(driver->getCabId()); //Finding a cab.
    driver->setCab(mainFlow->cab);
    mainFlow->sendUpdateCab(mainFlow->cab, descriptor); // Send cab to the client.
    mainFlow->taxiCenter->addDriver(driver);
    mainFlow->taxiCenter->addDescriptor(descriptor);
    mainFlow->numOfDrivers--;
    pthread_mutex_unlock(&clientLock);

    AbstractNode *node = driver->getcurrentPoint();
    while (true) {
        if (mainFlow->flagCase == 9) {
            if ((*(driver->getcurrentPoint()) != (*node))) {
                // Send the driver to the client.
                LINFO << "9 in thread\n";
                mainFlow->sendUpdateDriver(driver, descriptor);
                node = driver->getcurrentPoint();
            }
        }
        if (mainFlow->flagCase == 7) {
            LINFO << "7 in thread\n";
            break;
        }
    }
}

void MainFlow::scanMapAndObstacles() {
    int numOfObstacles, px, py;
    string input;
    bool validInput = false;
    while (!validInput) {

        this->inputValid->setStr(inputValid->getInput());
        inputByChar = this->inputValid->splitString(' ');
        mapX = this->inputValid->checkInt(inputByChar[0]);
        mapY = this->inputValid->checkInt(inputByChar[1]);

        if (!this->inputValid->isValidMap(inputByChar.size(), mapX, mapY)) {
            cout << "-1\n";
            LINFO << "map is not good\n";
            continue;
        }

        this->inputValid->setStr(inputValid->getInput());
        inputByChar = this->inputValid->splitString(' ');
        numOfObstacles = this->inputValid->checkInt(inputByChar[0]);
        if (inputByChar.size() != 1 || numOfObstacles < 0) {
            cout << "-1\n";
            LINFO << "numOfObstacles is not good\n";
            continue;
        }

        while (numOfObstacles > 0) { // Get the points of the obstacles.
            this->inputValid->setStr(inputValid->getInput());
            inputByChar = this->inputValid->splitString(',');
            px = this->inputValid->checkInt(inputByChar[0]);
            py = this->inputValid->checkInt(inputByChar[1]);

            //TODO if > or >=
            if (px >= mapX || px < 0 || py >= mapY || py < 0) {
                cout << "-1\n";
                LINFO << "Obstacles is not good\n";
                break;
            } else {
                obstacles.push_back(Point(px, py));
                numOfObstacles--;
            }
        }
        if (numOfObstacles>0){
            continue;
        }
        validInput = true;
    }
    this->map = this->MapParser(mapX, mapY);
    for (int i = 0; i < (int) obstacles.size(); i++) {
        Point p = obstacles[i];
        this->map->getSourceElement(p.getX(), p.getY())->setObstacle(true);
    }
}

void MainFlow::scanCab() {

    int cabId, cabType;
    char manufacturer;
    char color;
    vector<string> inputByChar;
    this->inputValid->setStr(inputValid->getInput());
    inputByChar = this->inputValid->splitString(',');

    if (inputByChar.size() != 4) {
        cout << "-1" << endl;
        LINFO << "Less or more arguments in cab\n";
        return;
    }

    cabId = this->inputValid->checkInt(inputByChar[0]);
    cabType = this->inputValid->checkInt(inputByChar[1]);
    manufacturer = inputByChar[2].at(0);
    color = inputByChar[3].at(0);

    if (!inputValid->isValidCab(cabId, cabType, inputByChar[2], inputByChar[3])) {
        cout << "-1" << endl;
        LINFO << "Cab is not valid\n";
        return;
    }

    // Check if the cab has the same id.
    unsigned long sizeCab = this->taxiCenter->getCabVec().size();
    for (int i = 0; i < sizeCab; i++) {
        if (cabId == this->taxiCenter->getCabVec()[i]->getCabId()) {
            cout << "-1" << endl;
            LINFO << "Cab id is occupied\n";
            return;
        }
    }

    this->cab = this->cabParser(cabId, cabType, manufacturer, color);
    taxiCenter->addCab(this->cab);

}

void MainFlow::scanTrip(int mapX, int mapY, Grid *map) {
    int tripId, startX, startY, endX, endY, numOfPassengers, time;
    double tariff;

    this->inputValid->setStr(inputValid->getInput());
    inputByChar = inputValid->splitString(',');
    
    // Check the length of the vector.
    if (inputByChar.size() != 8) {
        cout << "-1" << endl;
        LINFO << "Less or more arguments in trip\n";
        return;
    }
   
    // Get the types to all the members.
    tripId = inputValid->checkInt(inputByChar[0]);
    startX = inputValid->checkInt(inputByChar[1]);
    startY = inputValid->checkInt(inputByChar[2]);
    endX = inputValid->checkInt(inputByChar[3]);
    endY = inputValid->checkInt(inputByChar[4]);
    numOfPassengers = inputValid->checkInt(inputByChar[5]);
    tariff = inputValid->checkDouble(inputByChar[6]);
    time = inputValid->checkInt(inputByChar[7]);

    // Check the valid of the members.
    if (!inputValid->isValidTrip(mapX, mapY, tripId, startX, startY,
                                 endX, endY, numOfPassengers, tariff, time)) {
        cout << "-1" << endl;
        LINFO << "trip invalid\n";
        return;
    }

    // Check if the trip has the same id.
    unsigned long sizeVecTrip = this->taxiCenter->getTripQueue().size();
    for (int j = 0; j < sizeVecTrip; j++) {
        if (tripId == this->taxiCenter->getTripQueue()[j]->getRideId()) {
            cout << "-1" << endl;
            LINFO << "trip id is occupied\n";
            return;
        }
    }

    // Create trip if is valid.
    this->tripInformation = tripInfoParser(tripId, startX, startY, endX, endY, numOfPassengers,
                                           tariff, map, time);
    // Adding to the thread pool.
    this->job = new Job(tripInformation->settingTrack, (void *) tripInformation);
    this->threadpool->addJob(this->job);
    taxiCenter->addTrip(this->tripInformation); // add the trip to the list.
}

int MainFlow::scanNum() {
    this->inputValid->setStr(inputValid->getInput());
    inputByChar = this->inputValid->splitString(' ');
    if (inputByChar.size() != 1 || inputValid->checkInt(inputByChar[0]) < 0) {
        cout << "-1\n";
        LINFO << "num of driver is not good\n";
    }
    return inputValid->checkInt(inputByChar[0]);
}

