/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:58:48 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/19 19:00:35 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "colors.h"

#define USAGE YELLOW "Valid commands: ADD, SEARCH or EXIT" RESET

int main()
{
	PhoneBook phonebook;

	while (std::cin.good())
	{
		std::string command;
		std::cout << BLUE "Enter a command: " RESET;
		std::getline(std::cin, command);
		// Trim whitespaces
		command.erase(command.find_last_not_of(" \n\r\t") + 1);
		command.erase(0, command.find_first_not_of(" \n\r\t"));
		if (command == "EXIT")
			return (0);
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else
			std::cout << USAGE << std::endl;
	}
}
