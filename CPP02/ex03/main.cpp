/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:09:52 by aurban            #+#    #+#             */
/*   Updated: 2024/04/12 15:46:47 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {

	Point a = Point(Fixed(0), Fixed(0));
	Point b = Point(Fixed(4), Fixed(0));
	Point c = Point(Fixed(0), Fixed(4));

	Point points[] = {Point(Fixed(0), Fixed(0)), \
		Point(Fixed(1), Fixed(1)),
		Point(Fixed(-1), Fixed(-1)),
		Point(Fixed(1), Fixed(30)),
		Point(Fixed(1.8f), Fixed(1.8f))};

	for (int i = 0; i < 5; i++)
	{
		Point p = points[i];
		bool isInside = bsp(a, b, c, p);
		if (isInside)
			std::cout << "The point " << p.getX() << "x;" << p.getY() << "y is inside the triangle" << std::endl;
		else
			std::cout << "The point " << p.getX() << "x;" << p.getY() << "y is outside the triangle" << std::endl;
		std::cout << std::endl;
	}
	return 0;
}