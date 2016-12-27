#ifndef ASS1_POINT_H
#define ASS1_POINT_H

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

// A Point class contains a x coordinate and y coordinate.
using namespace std;
using namespace boost::archive;
using namespace boost::serialization;

//std::stringstream ss;
class Point {
    friend class access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & x;
        ar & y;
    }
private:
    // Members.
    int x, y;
    void validate();

public:
    // A constructor.
    Point(int dx = 0, int dy = 0);

    // A destructor.
    ~Point();

    // Getting x coordinate.
    int getY() const;

    // Getting y coordinate.
    int getX() const;

    // Calculating the distance.
    double distance(Point other);

    // Setting y coordinate.
    void setY(int newY);

    // Setting x coordinate.
    void setX(int newX);

    // Overriding the + operator.
    Point operator+(const Point &p1) const;

    // Overriding the << operator.
    friend ostream &operator<<(std::ostream &os, const Point &p);

    bool operator==(const Point &point) const;

    bool operator!=(const Point &point) const;

};


#endif //ASS1_POINT_H