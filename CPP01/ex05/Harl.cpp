/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:09:26 by aurban            #+#    #+#             */
/*   Updated: 2024/02/20 16:21:43 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::Harl(Harl const &cpy)
{
	(void)cpy;
}

Harl::~Harl()
{
}

Harl &Harl::operator=(Harl const &cpy)
{
	(void)cpy;
	return *this;
}

void Harl::debug( void )
{
	std::cout << "Debug" << std::endl;
}

void Harl::info( void )
{
	std::cout << "Info" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "Warning" << std::endl;
}

void Harl::error( void )
{
	std::cout << "Error" << std::endl;
}

void Harl::complain( std::string level)
{
	std::string levels[4]		= {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*foo[4])(void)	= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*foo[i])();
			return ;
		}
	}
	std::cout << "Unknown level" << std::endl;
}

