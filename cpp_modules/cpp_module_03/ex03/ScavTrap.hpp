/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:30:21 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/02 19:39:03 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{

public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &copy);
	~ScavTrap(void);

	ScavTrap &operator=(ScavTrap const &src);

	void guardGate(void);
	void attack(const std::string &target);

protected:
	static const int INITIAL_HITPOINTS = 100;
	static const int INITIAL_ENERGYPOINTS = 50;
	static const int INITIAL_ATTACKDAMAGE = 20;

private:
	bool _guardGateMode;
};

#endif
