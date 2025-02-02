/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:29:38 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/02 00:00:08 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FragTrap ft("FragTrap");

	ft.attack("Skag");
	ft.highFivesGuys();
	ft.takeDamage(1000);
	ft.highFivesGuys();

	return (0);
}

/*
ClapTrap Constructor called for FragTrap
FragTrap Constructor called for FragTrap
ClapTrap FragTrap attacks Skag, causing 30 points of damage!
FragTrap FragTrap: Guys you want to high five?
ClapTrap FragTrap took 1000 damages!
FragTrap FragTrap is not able to high five!
FragTrap Destructor called
ClapTrap Destructor called
*/
