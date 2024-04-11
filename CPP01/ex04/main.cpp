/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:20:52 by aurban            #+#    #+#             */
/*   Updated: 2024/03/01 15:51:26 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

int	replace_my_file(std::ifstream &file_in, std::string filename , std::string const find, std::string const replace)
{
	std::string	line;
	std::string	replaced_line;

	// Creates or open a a file for output, truncating its contents if it existed before
	std::ofstream	file_out((filename + ".replace").c_str(), std::ios::out | std::ios::trunc);
	if (!file_out.is_open())
	{
		std::cout << "Error: " << filename << ".replace creation failed" << std::endl;
		return 1;
	}
	while (std::getline(file_in, line))
	{
		if (line.empty())
		{
			file_out << std::endl;
			continue;
		}
		replaced_line.clear();
		replaced_line.reserve(line.length() + replace.length());
		size_t	pos = 0;
		while (line[pos])
		{
			replaced_line += line[pos];
			size_t match = line.find(find, pos);
			if (match == pos)
			{
				replaced_line += replace;
				pos += find.length();
			}
			else
				pos++;
		}
		file_out << replaced_line << std::endl;
	}
	return 0;
}

void input_print_error()
{
	std::cout << "Usage: \n\t" << "arg[0]" << " <file_name>\n";
	std::cout << "\t" << "arg[1]" << " <find>\n";
	std::cout << "\t" << "arg[2]" << " <replace>" << std::endl;
}

int main(int ac, char *av[])
{
	if (ac < 4)
	{
		input_print_error();
		return 1;
	}

	std::string filename = av[1];
	std::string find = av[2];
	std::string replace = av[3];

	if (find.empty())
	{
		std::cout << "Error: <find> cannot be empty" << std::endl;
		return 1;
	}

	std::ifstream file_stream(filename.c_str(), std::ios::in);
	if (!file_stream.is_open())
	{
		std::cout << "Error: file `" << filename << "' does not exist or permission denied" << std::endl;
		return 1;
	}
	int ret = replace_my_file(file_stream, filename, find, replace);
	file_stream.close();
	if (ret)
	{
		std::cout << "Error: " << filename << " replacement failed" << std::endl;
		return 1;
	}
	return 0;
}