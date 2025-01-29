/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:07:50 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/22 12:18:40 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n"
			  << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl
			  << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n"
			  << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl
			  << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n"
			  << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl
			  << "This is unacceptable! I want to speak to the manager now.\n"
			  << std::endl;
}

const std::string Harl::LEVELS[MAX_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};

void Harl::complain(std::string level)
{
	int i = 0;
	while (i < MAX_LEVELS && level != LEVELS[i])
		i++;
	switch (i)
	{
	case 0:
		debug();
	case 1:
		info();
	case 2:
		warning();
	case 3:
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
