/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:29:49 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/01 23:55:22 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	if (this == &src)
		return;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src)
{
	std::cout << "ClapTrap Assignment operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._hitPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints < 1 || _energyPoints < 1)
	{
		std::cout << "ClapTrap " << _name << " is not able to attack!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints < 1)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " took " << amount << " damages!" << std::endl;
	if (_hitPoints < amount)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints < 1 || _energyPoints < 1)
	{
		std::cout << "ClapTrap " << _name << " is not able to repair itself!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " repaired " << amount << " hit points!" << std::endl;
	_hitPoints += amount;
	_energyPoints--;
}
