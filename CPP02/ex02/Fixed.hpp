/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:40:23 by aurban            #+#    #+#             */
/*   Updated: 2024/04/11 11:32:16 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cmath>
#define EPSILON 0.001

class Fixed
{
private:
	int					_value;
	static const int	_bits = 8;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value	);
	~Fixed();
	Fixed(const Fixed &src);

	Fixed	&operator=(const Fixed &right);

	Fixed	operator+(const Fixed &right);
	Fixed	operator-(const Fixed &right);
	Fixed	operator*(const Fixed &right);
	Fixed	operator/(const Fixed &right);

	bool	operator>(const Fixed &right);
	bool	operator>=(const Fixed &right);
	bool	operator<(const Fixed &right);
	bool	operator<=(const Fixed &right);
	bool	operator==(const Fixed &right);
	bool	operator!=(const Fixed &right);

	Fixed	&operator++(void);
	Fixed	&operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed 		&min(Fixed &a, Fixed &b);
	static Fixed 		&max(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream& os,const Fixed& n);
