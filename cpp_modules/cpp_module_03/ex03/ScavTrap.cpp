/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:30:17 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/02 19:39:45 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	_hitPoints = INITIAL_HITPOINTS;
	_energyPoints = INITIAL_ENERGYPOINTS;
	_attackDamage = INITIAL_ATTACKDAMAGE;
	_guardGateMode = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor called for " << name << std::endl;
	_hitPoints = INITIAL_HITPOINTS;
	_energyPoints = INITIAL_ENERGYPOINTS;
	_attackDamage = INITIAL_ATTACKDAMAGE;
	_guardGateMode = false;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	_guardGateMode = copy._guardGateMode;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src)
{
	std::cout << "ScavTrap Assignment operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	this->_guardGateMode = src._guardGateMode;
	return (*this);
}

void ScavTrap::attack(std::string const &target)
{
	if (_hitPoints < 1 || _energyPoints < 1)
	{
		std::cout << "ScavTrap " << _name << " is not able to attack!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ScavTrap::guardGate(void)
{
	if (_hitPoints < 1 || _energyPoints < 1 || _guardGateMode == true)
	{
		std::cout << "ScavTrap " << _name << " is not able to enter Gate keeper mode!" << std::endl;
		return;
	}
	std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;
	_guardGateMode = true;
}
