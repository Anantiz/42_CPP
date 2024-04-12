#pragma once

#include "Fixed.hpp"

class Point{
private:

	Fixed _x;
	Fixed _y;

public:

	Point(void);
    Point(Fixed x, Fixed y);
	~Point();
	Point(const Point &src);

    Fixed getX(void) const;
    Fixed getY(void) const;
    void setX(Fixed x);
    void setY(Fixed y);

	static Fixed	getArea(const Point& a, const Point& b, const Point& c);

};

bool	bsp(const Point& a, const Point& b, const Point& c, const Point& p);
