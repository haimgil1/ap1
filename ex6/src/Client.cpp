#include "Tcp.h"
#include "Client.h"

#include "easylogging++.h"
#include "InputValid.h"

using namespace std;
using namespace boost::iostreams;
using namespace boost::archive;

using namespace std;

int main(int argc, char *argv[]) {
    Client client(argv[2]);
    client.scanDriver();
    client.sendDriver(argv[2]);
    client.receiveCab();
    client.updateDriver();
    return 0;
}

Client::Client() {

}

Client::~Client() {
    delete driver;
    delete tcp;
}

Client::Client(char *argv) {
//    this->tcp = new Tcp(0, atoi(argv)); // Set the tcp.
//    this->tcp->initialize();
    this->end = buffer + 64999;
    this->driver = NULL;
    this->cab = NULL;
    this->node = new Node(Point(0, 0), NULL);
}

void Client::scanDriver() {
    string input;
    int driverId, vehicleId;
    double age, experience;
    MaritalStatus maritalStatus;
    getline (cin, input); // Getting the input.
    InputValid inputValid(input);
    vector<string> inputByChar = inputValid.splitString(',');
    if (inputByChar.size() != 5) {
        exit(0);
    } else {
        driverId = inputValid.checkInt(inputByChar[0]);
        age = inputValid.checkInt(inputByChar[1]);
        maritalStatus = MaritalStatus(inputByChar[2].at(0));
        experience = inputValid.checkInt(inputByChar[3]);
        vehicleId = inputValid.checkInt(inputByChar[4]);
        if (!inputValid.isValidDriver(driverId, age, inputByChar[2], experience, vehicleId)) {
            exit(0);
        }
    }
    this->driver = new Driver(driverId, age, maritalStatus, experience, vehicleId, node);
}

void Client::receiveCab() {
    this->tcp->reciveData(buffer, sizeof(buffer), 1);
    basic_array_source<char> device(buffer, end);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(
            device);
    binary_iarchive ia(s2);
    ia >> this->cab;
    this->driver->setCab(this->cab);
    LINFO << "recieve cab\n";
   
}

void Client::sendDriver(char *argv) {
    this->tcp = new Tcp(0, atoi(argv)); // Set the tcp.
    this->tcp->initialize();
    string serial_str;
    back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    binary_oarchive oa(s);
    oa << this->driver;
    s.flush();
    this->tcp->sendData(serial_str,1);
   
    LINFO << "send Driver\n";
}

void Client::updateDriver() {
    while (true) {
        // check if the driver is not null to delete driver.
        if (this->driver != NULL) {
            // check if the point in the driver is not null to delete the point.
            if (this->driver->getcurrentPoint() != NULL) {
                delete this->driver->getcurrentPoint();
            }
            delete this->driver;
            this->driver = NULL;
        }
        
        // get the driver from the server.
        this->tcp->reciveData(buffer, sizeof(buffer),1);
        basic_array_source<char> device(buffer, end);
        boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(
                device);
        binary_iarchive ia(s2);
        ia >> this->driver;
        LINFO << "got driver\n";
        LINFO << driver->getId();
        LINFO << *(driver->getcurrentPoint());
        

        if (this->driver->getId() == -1) { // check if close the client session.
            delete this->driver->getcurrentPoint(); // delete the driver.
            break;
        }
    }
}
