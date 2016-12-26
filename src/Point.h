#ifndef ASS1_POINT_H
#define ASS1_POINT_H

#include <ostream>
#include <stdexcept>
// A Point class contains a x coordinate and y coordinate.
using namespace std;

class Point {
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