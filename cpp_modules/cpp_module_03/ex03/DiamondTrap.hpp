/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:30:02 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/01 23:14:36 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/**
 * The DiamondTrap class inherits from ScavTrap and FragTrap
 * Multiple inheritance is possible in C++ but it can lead to the Diamond problem
 * See: https://en.wikipedia.org/wiki/Multiple_inheritance#The_diamond_problem
 */

/**
 * This inheritance is possible because both classes use virtual inheritance
 * This way, the compiler knows that there is only one instance of the base class
 * See: https://en.wikipedia.org/wiki/Virtual_inheritance
 */

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const &copy);
	~DiamondTrap(void);

	DiamondTrap &operator=(DiamondTrap const &src);

	void whoAmI(void);

private:
	std::string _name;
};

#endif
