
#ifndef EX4_CLIENT_H
#define EX4_CLIENT_H

#include "Driver.h"
#include "Socket.h"
#include <ostream>
#include <stdexcept>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/vector.hpp>

class Client {
public:
    Client();

    // Constructor.
    Client(char *argv);

    // Distructor.
    virtual ~Client();

    // Scannig a driver.
    void scanDriver();

    // Send  the driver to the server.
    void sendDriver(char *argv);

    // Receive a cab from the server.
    void receiveCab();

    // Receive the update driver after moving one step.
    void updateDriver();

private:
    //Members.
    Socket *tcp;
    char buffer[65000];
    char *end;
    Driver *driver;
    Cab *cab;
    AbstractNode *node;
    //int accept;
};

#endif //EX4_CLIENT_H
