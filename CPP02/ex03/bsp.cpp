#include "Point.hpp"
#include "Fixed.hpp"

// Absolute surface area of a triangle
Fixed	Point::getArea(const Point& a, const Point& b, const Point& c)
{
	Fixed	area = (\
	a.getX() * (b.getY() - c.getY()) \
	+ b.getX() * (c.getY() - a.getY()) \
	+ c.getX() * (a.getY() - b.getY())) \
	/ Fixed(2);

	return Fixed::abs(area);
}

bool	bsp(const Point& a, const Point& b, const Point& c, const Point& p)
{
	Fixed	A		= Point::getArea(a, b, c);
	Fixed	Apbc	= Point::getArea(p, b, c);
	Fixed	Aapc	= Point::getArea(a, p, c);
	Fixed	Aabp	= Point::getArea(a, b, p);

	// Debug
	std::cout << "A: " << A << std::endl;
	std::cout << "Apbc: " << Apbc << std::endl;
	std::cout << "Aapc: " << Aapc << std::endl;
	std::cout << "Aabp: " << Aabp << std::endl;
	std::cout << "Combined: " << (Apbc + Aapc + Aabp) << std::endl;

	if (A == Fixed(0) || Apbc == Fixed(0) || Aapc == Fixed(0) || Aabp == Fixed(0))
		return false;

	if ((Apbc + Aapc + Aabp) - A < Fixed(0.01f) && (Apbc + Aapc + Aabp) - A > Fixed(-0.01f))
		return true;
	return false;
}

