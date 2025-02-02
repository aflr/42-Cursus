/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:28:53 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/01 23:52:36 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap ct("ClapTrap");

	ct.attack("Skag 1");
	ct.takeDamage(3);
	ct.beRepaired(10);

	ct.takeDamage(30);
	ct.attack("Skag 2");
	ct.takeDamage(1);

	return (0);
}

/*
ClapTrap Constructor called for ClapTrap
ClapTrap ClapTrap attacks Skag 1, causing 0 points of damage!
ClapTrap ClapTrap took 3 damages!
ClapTrap ClapTrap repaired 10 hit points!
ClapTrap ClapTrap took 30 damages!
ClapTrap ClapTrap is not able to attack!
ClapTrap ClapTrap is already dead!
ClapTrap Destructor called
*/
