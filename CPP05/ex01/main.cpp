/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:58:09 by aurban            #+#    #+#             */
/*   Updated: 2024/05/04 17:37:41 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main()
{
	Bureaucrat		DTrumpJunior("DTrumpJunior", 1);
	Bureaucrat		Biden("Biden", 150);

	Form			ligma("ligma", 1, 1);
	Form			sugondeez("sugondeez", 1, 1);
	Form			sugondeez2(sugondeez);

	std::cout << ligma << std::endl;
	try{
		ligma.beSigned(DTrumpJunior);
	}catch (const Form::GradeTooLowException & e){
		std::cout << e.what() << std::endl;
	}

	std::cout << sugondeez << std::endl;
	try{
		sugondeez.beSigned(Biden);
	}catch (const Form::GradeTooLowException & e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}