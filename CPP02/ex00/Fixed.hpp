/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:40:23 by aurban            #+#    #+#             */
/*   Updated: 2024/02/20 18:43:18 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
private:
	int					value;
	static const int	bits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &src);

	Fixed &operator=(const Fixed &src);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};