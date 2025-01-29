/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:06:32 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/22 17:36:47 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // cout, endl
#include <fstream> // is_open, open, close
#include <string> // string, getline, etc.
#include <iosfwd> // ifstream, ofstream (forward declaration)
#include <cstddef> // size_t
#include "colors.h"

int main(int ac, char **av)
{
	// Argument count validation
	if (ac != 4)
	{
		std::cout << YELLOW "Usage: ./sed [filename] [s1] [s2]" RESET << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::string target = av[2];
	std::string replacement = av[3];

	// Argument value validation
	if (target.empty())
	{
		std::cout << RED "Error: Empty target string is not allowed" RESET << std::endl;
		return (1);
	}
	if (filename.empty())
	{
		std::cout << RED "Error: Empty filename is not allowed" RESET << std::endl;
		return (1);
	}

	// Open file
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << RED "Error: Could not open file" RESET << std::endl;
		return (1);
	}

	// Create output file
	std::string outputFilename = filename + ".replace";
	std::ofstream output(outputFilename.c_str());
	if (!output.is_open())
	{
		std::cout << RED "Error: Could not create output file" RESET << std::endl;
		file.close();
		return (1);
	}

	// Replace target with replacement, without using std::string::replace
	std::string line;
	while (std::getline(file, line))
	{
		size_t start = 0;
		size_t end = 0;
		while ((end = line.find(target, start)) != std::string::npos)
		{
			output << line.substr(start, end - start);
			output << replacement;
			start = end + target.length();
		}
		output << line.substr(start) << std::endl;
	}

	// Close files
	file.close();
	output.close();

	// Success message
	std::cout << GREEN "Successfully replaced \"" << target << "\" with \""
			<< replacement << "\" in " << filename << " and saved the result in "
			<< outputFilename << RESET << std::endl;
	return (0);
}
