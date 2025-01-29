/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:07:40 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/22 11:40:52 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl
			  << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl
			  << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl
			  << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

const std::string Harl::LEVELS[MAX_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};

void (Harl::*Harl::logLevelHandlers[MAX_LEVELS])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

void Harl::complain(std::string level)
{
	for (int i = 0; i < MAX_LEVELS; i++)
		if (level == LEVELS[i])
			return (this->*logLevelHandlers[i])();
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
