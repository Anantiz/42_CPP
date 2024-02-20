/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:06:38 by aurban            #+#    #+#             */
/*   Updated: 2024/02/20 16:16:05 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:

	Harl();
	Harl(Harl const &cpy);
	Harl &operator=(Harl const &cpy);
	~Harl();
	void	complain( std::string level);
};