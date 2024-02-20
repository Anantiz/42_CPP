/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:06:38 by aurban            #+#    #+#             */
/*   Updated: 2024/02/20 16:38:34 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

typedef enum Level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
}t_e_level;

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	
	void	log( t_e_level msg );
	t_e_level _min_level = DEBUG;

public:

	Harl();
	Harl(Harl const &cpy);
	Harl &operator=(Harl const &cpy);
	~Harl();
	void	complain( std::string level);
};