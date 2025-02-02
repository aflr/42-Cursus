/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:30:11 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/02 19:41:26 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap dt("DiamondTrap");

	dt.attack("Skag");
	dt.whoAmI();
	dt.guardGate();
	dt.highFivesGuys();
	dt.takeDamage(10);
	dt.beRepaired(10);

	return (0);
}

/*
ClapTrap Default Constructor called
ScavTrap Constructor called for DiamondTrap
FragTrap Constructor called for Default
DiamondTrap Constructor called for DiamondTrap
ScavTrap DiamondTrap_clap_name attacks Skag, causing 30 points of damage!
DiamondTrap ClapTrap's name is DiamondTrap_clap_name!
ScavTrap is now in Gate keeper mode!
FragTrap DiamondTrap_clap_name: Guys you want to high five?
ClapTrap DiamondTrap_clap_name took 10 damages!
ClapTrap DiamondTrap_clap_name repaired 10 hit points!
DiamondTrap Destructor called
FragTrap Destructor called
ScavTrap Destructor called
ClapTrap Destructor called
*/