//
// Created by haim gil on 28 Nov 2016.
//

#ifndef TASK2BFS_CABBASE_H
#define TASK2BFS_CABBASE_H

#include <string>
#include "CarManufacturer.h"
#include "Color.h"
#include "AbstractNode.h"
#include <stack>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/export.hpp>

using namespace std;

/* Class: Cab.
 * The class contains detail on cab and some functions on cab.*/
class Cab {
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & cabId;
        ar & klmPassed;
        ar & manufacturer;
        ar & color;
    }

protected:
    // Members.
    int cabId;
    int klmPassed;
    CarManufacturer manufacturer;
    Color color;
public:
    // Default constructor.
    Cab();

    // Constructor - update the members to the parameters of the constructor gets.
    Cab(int cabId, CarManufacturer manufacturer,
        Color color);

    virtual ~Cab() = 0;

    // The function returns the id of the cab.
    int getCabId();

    // The function returns the number of kilometers of the cab.
    int getKilometerPassed();

    // The function returns the kind of cab manufacturer.
    CarManufacturer getManufacturer();

    // The function returns the color of the cab.
    Color getColor();

    // Set the cab id.
    void setCabId(int cabID);

    // Set the kilometer passed of the cab.
    void setKilometerPassed(int klm);

    // Set the cer manufacturer of the cab.
    void setManufacturer(CarManufacturer manufacturer);

    // Set the color of the cab.
    void setColor(Color color);

    /* Virtual function getCoefficient: each kind of cabs standard
     * or luxury calculates the tariff by their definition. */
    virtual int getCoefficient()=0;

    /* Virtual function moveOneStep: each kind of cabs standard
     * or luxury change the new block by their definition. */
    virtual AbstractNode *moveOneStep(stack<AbstractNode *> *track, Point endPoint)=0;

    // Set the operator ==.
    bool operator==(const Cab &cab) const;

    // Set the operator !=.
    bool operator!=(const Cab &cab) const;
};

BOOST_SERIALIZATION_ASSUME_ABSTRACT(Cab)
#endif //TASK2BFS_CABBASE_H
