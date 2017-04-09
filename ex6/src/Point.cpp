
#include "Point.h"

using namespace std;

Point::Point(int dx, int dy) {
    x = dx;
    y = dy;
    this->validate();
}

Point::~Point() {

}

void Point::validate() {
    // Check the value of x and the value of y to be positive.
    if ((this->x < 0) || (this->y < 0)) {
        throw invalid_argument("can't get negative coordinate");
    }
}

int Point::getY() const {
    return this->y;
}

int Point::getX() const {
    return this->x;
}

double Point::distance(Point other) {
    int dx = x - other.x;
    int dy = y - other.y;
    return sqrt(dx * dx + dy * dy);
}

void Point::setY(int newY) {
    this->y = newY;
}

void Point::setX(int newX) {
    this->x = newX;
}

Point Point::operator+(const Point &p1) const {
    return Point((x + p1.x) + (y + p1.y));
}

ostream &operator<<(ostream &os, const Point &p) {
    return os << "(" << p.x << "," << p.y << ")" << endl;
}

bool Point::operator==(const Point &point) const {
    return x == point.x &&
           y == point.y;
}

bool Point::operator!=(const Point &point) const {
    return !(point == *this);
}

