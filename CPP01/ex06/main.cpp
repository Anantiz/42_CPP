/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:19:42 by aurban            #+#    #+#             */
/*   Updated: 2024/02/20 16:46:57 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// NOT FUCKING DOABLE WITH A SWITCH, WTF IS EVEN THE SUBJECT ASKING ?????????????????????????

#include "Harl.hpp"

int main(int ac, char *av[])
{
	Harl h;

	if (ac != 2)
	{
		std::cout << "Usage: \n\t" << "arg[0]" << " <lowest_level_to_display>" << std::endl;
		return 1;
	}

	h.complain("DEBUG");
	h.complain("INFO");
	h.complain("WARNING");
	h.complain("ERROR");
	return 0;
}