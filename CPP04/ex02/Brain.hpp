/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:51:44 by aurban            #+#    #+#             */
/*   Updated: 2024/04/13 10:52:39 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Brain
{
protected:

	std::string ideas[100];

public:

	Brain();
	Brain(const Brain &copy);
	~Brain();
	Brain &operator=(const Brain &copy);

	std::string getIdea(int i) const;
	void setIdea(int i, std::string idea);
};
