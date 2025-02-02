/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:30:00 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/02 19:40:38 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ScavTrap("Default"), FragTrap("Default")
{
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
	ClapTrap::_name = "Default_clap_name";
	this->_name = "Default";
	this->_hitPoints = FragTrap::INITIAL_HITPOINTS;
	this->_energyPoints = ScavTrap::INITIAL_ENERGYPOINTS;
	this->_attackDamage = FragTrap::INITIAL_ATTACKDAMAGE;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap Constructor called for " << name << std::endl;
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_hitPoints = FragTrap::INITIAL_HITPOINTS;
	this->_energyPoints = ScavTrap::INITIAL_ENERGYPOINTS;
	this->_attackDamage = FragTrap::INITIAL_ATTACKDAMAGE;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ScavTrap(copy), FragTrap(copy)
{
	std::cout << "DiamonTrap Copy Constructor called" << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &src)
{
	std::cout << "DiamondTrap Assignment operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << _name << " ClapTrap's name is " << ClapTrap::_name << "!" << std::endl;
}
