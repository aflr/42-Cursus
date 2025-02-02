/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:30:05 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/02 19:38:25 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
	_hitPoints = INITIAL_HITPOINTS;
	_energyPoints = INITIAL_ENERGYPOINTS;
	_attackDamage = INITIAL_ATTACKDAMAGE;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Constructor called for " << _name << std::endl;
	_hitPoints = INITIAL_HITPOINTS;
	_energyPoints = INITIAL_ENERGYPOINTS;
	_attackDamage = INITIAL_ATTACKDAMAGE;
}

FragTrap::FragTrap(FragTrap const &copy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
	if (this == &copy)
		return;
	*this = copy;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &src)
{
	std::cout << "FragTrap Assignment operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if (_hitPoints < 1 || _energyPoints < 1)
	{
		std::cout << "FragTrap " << _name << " is not able to high five!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << ": Guys you want to high five?" << std::endl;
}
