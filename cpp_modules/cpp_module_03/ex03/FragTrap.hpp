/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:30:08 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/02 19:37:34 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const &copy);
	~FragTrap(void);

	FragTrap &operator=(FragTrap const &src);

	void highFivesGuys(void);

protected:
	static const int INITIAL_HITPOINTS = 100;
	static const int INITIAL_ENERGYPOINTS = 100;
	static const int INITIAL_ATTACKDAMAGE = 30;

};

#endif
