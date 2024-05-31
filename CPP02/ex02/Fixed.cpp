/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:43:02 by aurban            #+#    #+#             */
/*   Updated: 2024/05/31 02:18:20 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static double my_pow(double base, int count)
{
	double res = 1;

	for (int i = 0; i < count; i++)
		res *= base;
	return res;
}

Fixed::Fixed() : _value(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int value)
{
	this->_value = value << _bits;
}

Fixed::Fixed(const float value)
{
	int		whole_part = roundf(value);
	int		decimal_part = (value - whole_part) * my_pow(2, _bits);

	this->_value = (whole_part << _bits) + decimal_part;
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	_value = src.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& os,const Fixed& n)
{
	os << n.toFloat();
	return os;
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	float	whole_part = _value >> _bits;
	float	decimal_part = _value & 0b11111111;

	return whole_part + (decimal_part / my_pow(2, _bits));
}

int Fixed::toInt(void) const{
	return _value >> _bits;
}

Fixed Fixed::operator+(const Fixed &right){
	return Fixed(this->toFloat() + right.toFloat());
}

Fixed Fixed::operator-(const Fixed &right){
	return Fixed(this->toFloat() - right.toFloat());
}

Fixed Fixed::operator*(const Fixed &right){
	return Fixed(this->toFloat() * right.toFloat());
}

Fixed Fixed::operator/(const Fixed &right){
	return Fixed(this->toFloat() / right.toFloat());
}

bool	Fixed::operator>(const Fixed &right){
	return this->toFloat() > right.toFloat();
}

bool	Fixed::operator>=(const Fixed &right){
	return this->toFloat() >= right.toFloat();
}

bool	Fixed::operator<(const Fixed &right){
	return this->toFloat() < right.toFloat();
}

bool	Fixed::operator<=(const Fixed &right){
	return this->toFloat() <= right.toFloat();
}

bool	Fixed::operator==(const Fixed &right){
	return this->toFloat() == right.toFloat();
}

bool	Fixed::operator!=(const Fixed &right){
	return this->toFloat() != right.toFloat();
}

Fixed &Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed &Fixed::operator--()
{
	this->_value--;
	return *this;
}


Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
	return a.toFloat() < b.toFloat() ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	return a.toFloat() > b.toFloat() ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	return a.toFloat() < b.toFloat() ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	return a.toFloat() > b.toFloat() ? a : b;
}

