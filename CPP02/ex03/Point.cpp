#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}
Point::Point(Fixed x, Fixed y) : _x(x), _y(y) {}
Point::~Point() {}
Point::Point(const Point &src) : _x(src._x), _y(src._y) {}

Fixed Point::getX(void) const { return _x; }
Fixed Point::getY(void) const { return _y; }
void Point::setX(Fixed x) { _x = x; }
void Point::setY(Fixed y) { _y = y; }

